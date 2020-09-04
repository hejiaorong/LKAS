%% ���ݽӿ��ĵ��Զ�����ģ�ͽű�
close('all');
if questdlg('�˲������ر�����EXCEL��ACCESS������ȷ�ϣ�','����','��','��','��')=='��'
    return;
end
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'EXCEL.EXE',32,'/T'));
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'MSACCESS.EXE',32,'/T'));
%% 1.����ģ���еĹ۲����������ݿ��ļ��ź�
path = cd;
monxlspath = strcat(cd,'\Tools\CANMaster');
fprintf('1.ȷ��Ŀ���ļ���Ŀ¼���С�CAN_Protocol_Raw.xlsx���ļ���ͬʱ���ļ�δ����\n');
monxlsFileName=strcat(monxlspath,'\CAN_Protocol_Raw.xlsx'); %  *�ű���excel�����ļ�����ͬһ���ļ��и��ļ���������ֻ��һ���ļ�xlsx�ļ�

opts = spreadsheetImportOptions("NumVariables", 16);
opts.Sheet = 1; %excel �ڼ�ҳ����
opts.DataRange = "A:P"; 
opts.VariableNames = ["var_Name","Period","CAN_ID","bSEND","VAR_ID","DataType","start_bit","bit_length","offset","bitResolution","device","Unit","max_Value","min_Value","Comment","byte_order"];
opts.VariableTypes = ["string", "string", "string", "string", "string","string", "string", "string", "string", "string","string", "string", "string", "string", "string", "string"];
opts = setvaropts(opts, [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], "WhitespaceRule", "preserve");
opts = setvaropts(opts, [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], "EmptyFieldRule", "auto");
Monxlstable = readtable(monxlsFileName, opts, "UseExcel", false);    % ͬһ���ļ������·�� % ��������
clear  opts;    % �����ʱ����
Monxlstable(1,:)=[];
%% 2.���ݹ۲������Ƹ������ݿ��ļ�
scriptpath = strcat(path,'\Script');
getFileName=ls(strcat(scriptpath,'\*.slx')); %  *�ű���slx����ͬһ���ļ��и��ļ���������ֻ��һ��slx�ļ�
FileNum = size(getFileName);
if  isequal(getFileName,'') % ��ֹѡ����ļ���
    fprintf('��ǰĿ¼��û���ҵ�*.slx�ļ�\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('��ǰĿ¼�´��ڲ�ֹ1��*.slx�ļ�\n');
    eval('clear all');
    return;
else
    fprintf('2.����Ŀ��*.slx�ļ���:��%s��\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
warning('off');
load_system(filename);
load_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'));
Monitor = find_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'),'SearchDepth',1,'BlockType','From');
MonitorNum = size(Monitor);
dist = Monitor{1};
for i = 1:MonitorNum(1)
    Monitor{i} = strcat(dist(1:length(dist)-1),num2str(i));
end
tag = {MonitorNum(1)};
text = {MonitorNum(1)};
for i = 1:MonitorNum(1)
    tag(i) = get_param(Monitor(i),'GotoTag');
    text(i) = get_param(Monitor(i),'Description');
%     set_param(Monitor{i},'Description',strcat('Monitor',num2str(i)));
end
id = 1536;
varid = 45;
a = [];
for i = 1 : MonitorNum(1)
    if contains(text(i),'-LKA')
        deviceid = '13';
    elseif contains(text(i),'-InP')
        deviceid = '12';
    else
        deviceid = '11';
    end
    addsignals = [strcat(tag(i),'_',num2str(i)),num2str(10),num2str(id+16*idivide(i-1,int32(4))),'0',num2str(varid+i),'1',num2str(7+mod(i-1,4)*16),'16','0','0.01',deviceid,'-','300','-300',text(i),'1'];
    Monxlstable = [Monxlstable;addsignals];
end
writetable(Monxlstable,strcat(monxlspath,'\CAN_Protocol.xls'));
fprintf('2.���Ĺ۲���������д���ļ���CAN_Protocol.xls��\n');
%% 3.���ݹ۲��������޸�dbc�ļ�
dbcfile = strcat(path,'\Documents\LKAS-Monitor.dbc');
newdbcfile = strcat(path,'\Documents\new-LKAS-Monitor.dbc');
dbcinifile = strcat(path,'\Documents\LKAS-Monitor.ini');
newdbcinifile = strcat(path,'\Documents\new-LKAS-Monitor.ini');
fid = fopen(newdbcfile,'wt');      %�½�һ��txt�ļ�  
fpn = fopen(dbcfile, 'rt');           %���ĵ�  
i = 1;
while feof(fpn) ~= 1                %�����ж��ļ�ָ��p������ָ���ļ��е�λ�ã�������ļ�ĩ����������1�����򷵻�0  
    line = fgetl(fpn);            %��ȡ�ĵ���һ��   
    if line == -1
        break;
    end
    if contains(line," SG_ ")&&contains(line,' "Mon" ')&&(i <= MonitorNum(1))
        new_str = regexpi(line,' ','split');
        new_str(3) = strcat(tag(i),num2str(i));
        newline = strjoin(new_str,' ');
        i = i + 1;
        fprintf(fid,'%s\n',newline);%�µ��ַ���д�뵱�½��ĵ���
    else
        fprintf(fid,'%s\n',line);%�µ��ַ���д�뵱�½��ĵ���
    end
end  
fclose(fid); 
fclose('all');
delete(dbcfile);
delete(dbcinifile);
delete(newdbcinifile);
eval(strcat('!rename',32,newdbcfile,32,'LKAS-Monitor.dbc'));
fprintf('3.���ġ�%s���ļ��Ѹ���\n',dbcfile);
%% 4.����DBC�ļ����¹۲�ģ���CANPackģ��
CANpack = find_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'),'MsgIDType','Standard (11-bit identifier)');
for i = 1:8
    set_param(CANpack{i},'DataFormat','CANdb specified signals');
    set_param(CANpack{i},'CANdbFile',dbcfile,'MsgList',strcat('Mon_',num2str(i)));
end
fprintf('4.���ġ�%s��ģ���Ѹ���\n',strcat(filename,'/CAN Monitor (CANMon)/Monitor'));
save_system(filename);