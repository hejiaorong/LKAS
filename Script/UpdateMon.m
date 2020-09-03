%% �Զ����¹۲���DBC�ļ�
eval('clear all');
eval('clc');
%% 1.��ģ�Ͳ���ȡ�۲�������
path = cd;
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
    fprintf('1.����Ŀ��*.slx�ļ���:[%s]\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
warning('off');
open_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'));
Monitor = find_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'),'SearchDepth',1,'BlockType','From');
MonitorNum = size(Monitor);
for i = 1:MonitorNum(1)
    Monitor(i) = get_param(Monitor(i),'GotoTag');
%     set_param(Monitor{i},'GotoTag','CLB_LKASWASyn_M0')
end
%% 2.���ݹ۲��������޸�dbc�ļ�
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
        new_str(3) = strcat(Monitor(i),num2str(i));
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
fprintf('2.���ġ�%s���ļ��Ѹ���\n',dbcfile);
%% 3.����DBC�ļ����¹۲�ģ���CANPackģ��
CANpack = find_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'),'MsgIDType','Standard (11-bit identifier)');
for i = 1:8
    set_param(CANpack{i},'DataFormat','CANdb specified signals');
    set_param(CANpack{i},'CANdbFile',dbcfile,'MsgList',strcat('Mon_',num2str(i)));
end
fprintf('3.���ġ�%s��ģ���Ѹ���\n',strcat(filename,'/CAN Monitor (CANMon)/Monitor'));