%% ����ģ�͹۲��������Զ����¹۲������ݿ�
if questdlg('�˲������ر�����EXCEL��ACCESS������ȷ�ϣ�','����','��','��','��')=='��'
    return;
end
eval('clear all');
eval('clc');
close('all');
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'EXCEL.EXE',32,'/T'));
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'MSACCESS.EXE',32,'/T'));
%% 1.�����ļ�
path = cd;
getModelName=ls(strcat(path,'\*.slx')); %  *�ű���slx����ͬһ���ļ��и��ļ���������ֻ��һ��slx�ļ�
FileNum = size(getModelName);
if  isequal(getModelName,'') % ��ֹѡ����ļ���
    fprintf('��ǰĿ¼��û���ҵ�*.slx�ļ�\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('��ǰĿ¼�´��ڲ�ֹ1��*.slx�ļ�\n');
    eval('clear all');
    return;
else
    fprintf('1.����Ŀ��*.slx�ļ���:��%s����',getModelName);
end
modelname = getModelName(1:length(getModelName)-4);    %��ȡslx�ļ���
scriptpath = strcat(path,'\Script');
getScriptName=ls(strcat(scriptpath,'\*.slx')); %  *�ű���slx����ͬһ���ļ��и��ļ���������ֻ��һ��slx�ļ�
FileNum = size(getScriptName);
if  isequal(getScriptName,'') % ��ֹѡ����ļ���
    fprintf('��ǰĿ¼��û���ҵ�*.slx�ļ�\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('��ǰĿ¼�´��ڲ�ֹ1��*.slx�ļ�\n');
    eval('clear all');
    return;
else
    fprintf('����Ŀ��*.slx�ļ���:��%s��\n',getScriptName);
end
scriptfile = getScriptName(1:length(getScriptName)-4);    %��ȡslx�ļ���
warning('off');
load_system(modelname);
load_system(strcat(modelname,'/',modelname,'/LL/LLOn'));
load_system(scriptfile);
load_system(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'));
%% 2.��ȡģ���еĹ۲�������
ModelMon = find_system(strcat(modelname,'/',modelname,'/LL'),'BlockType','Goto','TagVisibility','global');
totalnum = length(ModelMon);
realMon = cell(0,1);
MonPath = cell(0,1);
for i = 1:totalnum
    montag = get_param(ModelMon{i},'GotoTag');
    if contains(montag,'_Mon')
        realMon = [realMon;montag];
        MonPath = [MonPath;ModelMon(i)];
    end
end
ModelMon = realMon;
clear montag i realMon FileNum totalnum;
fprintf('2.�ѻ�ȡģ���еĹ۲�������\n');
%% 3.����ģ�͹۲�����ģ��
MonNum = length(ModelMon);
DelBlock = find_system(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'));
delete_line(strcat(modelname,'/',modelname,'/LL/LLOn'),'LKAMon/1','LL_Mon/1');
delete_line(strcat(modelname,'/',modelname,'/LL/LLOn'),'LL_Mon/1','LLMon/1');
delete_block(DelBlock(1));
add_block('Simulink/Commonly Used Blocks/Subsystem',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'Position',[1035 1070 1365 1150])
DelBlock = find_system(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'));
delete_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'In1/1','Out1/1');
DelBlock = DelBlock(2:3);
delete_block(DelBlock);
add_block('Simulink/Commonly Used Blocks/In1',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/LKAMon'),'Position',[1100 205 1130 225])
add_block('Simulink/Signal Routing/From',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/StateMon1'),'GotoTag','StateMon','Position',[1100 150 1180 180]);
add_block('Simulink/Signal Routing/From',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/InPMon1'),'GotoTag','InPMon','Position',[1100 100 1180 130]);
add_block('Simulink/Signal Routing/Bus Creator',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/Bus'),'Inputs','3','Position',[1250 090 1260 240]);
add_block('Simulink/Commonly Used Blocks/Out1',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/LLMon'),'Position',[1350 155 1380 175])
add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'InPMon1/1','Bus/1');
add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'StateMon1/1','Bus/2');
add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'LKAMon/1','Bus/3');
set_param(add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'Bus/1','LLMon/1'),'Name','LLMon');
add_line(strcat(modelname,'/',modelname,'/LL/LLOn'),'LKAMon/1','LL_Mon/1');
add_line(strcat(modelname,'/',modelname,'/LL/LLOn'),'LL_Mon/1','LLMon/1');
% ����LKAģ���еĹ۲����ģ��
DelBlock = find_system(strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon'));
delete_line(strcat(modelname,'/',modelname,'/LL/LLOn/LKA'),'LKA_Mon/1','LKAMon/1');
delete_block(DelBlock(1));
add_block('Simulink/Commonly Used Blocks/Subsystem',strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon'),'Position',[1945 900 2275 990]);
DelBlock = find_system(strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon'));
delete_line(strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon'),'In1/1','Out1/1');
DelBlock = DelBlock(2:3);
delete_block(DelBlock);
% ��ӹ۲���
q=0;w=0;e=0;
for i = 1:MonNum
    new_str = regexpi(MonPath{i},'/','split');
    if contains(new_str(5),'LKAInP')
        add_block('Simulink/Signal Routing/From',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/FromInP',num2str(q+1)),'GotoTag',ModelMon{i},'Position',[50 100+q*60 180 130+q*60]);
        q = q + 1;
    elseif contains(new_str(5),'LLStateDet')
        add_block('Simulink/Signal Routing/From',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/FromState',num2str(w+1)),'GotoTag',ModelMon{i},'Position',[550 100+w*60 680 130+w*60]);
        w = w + 1;
    elseif contains(new_str(5),'LKA')
        add_block('Simulink/Signal Routing/From',strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon/FromLKA',num2str(e+1)),'GotoTag',ModelMon{i},'Position',[50 100+e*60 180 130+e*60]);
        e = e + 1;
    else
    end
end
% �����۲�����
add_block('Simulink/Signal Routing/Bus Creator',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/BusInP'),'Inputs',num2str(q),'Position',[250 85 260 85+q*60]);
add_block('Simulink/Signal Routing/Goto',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/InPMon'),'GotoTag','InPMon','Position',[350 70+q*30 430 100+q*30]);
add_block('Simulink/Signal Routing/Bus Creator',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/BusState'),'Inputs',num2str(w),'Position',[750 85 760 85+w*60]);
add_block('Simulink/Signal Routing/Goto',strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/StateMon'),'GotoTag','StateMon','Position',[850 70+w*30 930 100+w*30]);
add_block('Simulink/Signal Routing/Bus Creator',strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon/BusLKA'),'Inputs',num2str(e),'Position',[250 85 260 85+e*60]);
add_block('Simulink/Commonly Used Blocks/Out1',strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon/LKAMon'),'Position',[350 70+e*30 430 100+e*30]);
add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LKA'),'LKA_Mon/1','LKAMon/1');
for i = 1:q
    tempname = get_param(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/FromInP',num2str(i)),'GotoTag');
    set_param(add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),strcat('FromInP',num2str(i),'/1'),strcat('BusInP/',num2str(i))),'Name',tempname);
end
for i = 1:w
    tempname = get_param(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon/FromState',num2str(i)),'GotoTag');
    set_param(add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),strcat('FromState',num2str(i),'/1'),strcat('BusState/',num2str(i))),'Name',tempname);
end
for i = 1:e
    tempname = get_param(strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon/FromLKA',num2str(i)),'GotoTag');
    set_param(add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon'),strcat('FromLKA',num2str(i),'/1'),strcat('BusLKA/',num2str(i))),'Name',tempname);
end
set_param(add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'BusInP/1','InPMon/1'),'Name','InPMon');
set_param(add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LL_Mon'),'BusState/1','StateMon/1'),'Name','StateMon');
set_param(add_line(strcat(modelname,'/',modelname,'/LL/LLOn/LKA/LKA_Mon'),'BusLKA/1','LKAMon/1'),'Name','LKAMon');
fprintf('3.�����ģ�͹۲�ģ����������\n');
%% 4.Ǩ��ģ�Ͳ����ÿ��ģ���еĹ۲�ģ��
SubSystName = find_system(modelname,'SearchDepth',1,'BlockType','SubSystem');
SubSystName = SubSystName{1};
delete_line(scriptfile,'LLClb/1','bsLLClb/1');
delete_line(scriptfile,'bsInInfo1/1','LL/1'); 
delete_line(scriptfile,'bsLLClb1/1','LL/2'); 
delete_line(scriptfile,'LL/1','LLOut/1'); 
delete_block(strcat(scriptfile,'/','LLClb'));
delete_block(strcat(scriptfile,'/','LL'));
add_block(strcat(modelname,'/',modelname,'/','LL'),strcat(scriptfile,'/LL'),'Position',[700 400 950 650]);
add_block(strcat(modelname,'/',modelname,'/','LLClb'),strcat(scriptfile,'/LLClb'),'Position',[100 415 350 515]);
add_line(scriptfile,'LLClb/1','bsLLClb/1');
add_line(scriptfile,'bsInInfo1/1','LL/1'); 
add_line(scriptfile,'bsLLClb1/1','LL/2'); 
add_line(scriptfile,'LL/1','LLOut/1'); 

DelBlock = find_system(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'),'BlockType','Goto');
for i = 1:length(DelBlock)
    DelBlockName = get_param(DelBlock(i),'Name');
    delete_line(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'),strcat('LLBus/',num2str(i)),strcat(DelBlockName{1},'/1'));
end
delete_block(DelBlock);
delete_line(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'),'LLMon/1','LLBus/1');
delete_block(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/LLBus'));
add_block('Simulink/Signal Routing/Bus Selector',strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/LLBus'),'Position',[1850 400-MonNum*30 1860 400+MonNum*30]);
set_param(add_line(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'),'LLMon/1','LLBus/1'),'Name','LLMon');
MonSignals = get_param(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/LLBus'),'InputSignals');
BusOut = '';
temp = 0;
for i = 1 : q
    add_block('Simulink/Signal Routing/Goto',strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/Mon',num2str(temp+1)),'Position',[1950 385-MonNum*30+30+temp*60 2050 415-MonNum*30+30+temp*60],'GotoTag',MonSignals{1,1}{1,2}{i,1});
    BusOut = strcat(BusOut,strcat(MonSignals{1,1}{1,1},'.',MonSignals{1,1}{1,2}{i,1}),',');
    set_param(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/Monitor',num2str(temp+1)),'GotoTag',MonSignals{1,1}{1,2}{i,1},'Description',strcat(MonSignals{1,1}{1,2}{i,1},'-InP'));
    temp = temp + 1;
end
for i = 1 : w
    add_block('Simulink/Signal Routing/Goto',strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/Mon',num2str(temp+1)),'Position',[1950 385-MonNum*30+30+temp*60 2050 415-MonNum*30+30+temp*60],'GotoTag',MonSignals{2,1}{1,2}{i,1});
    BusOut = strcat(BusOut,strcat(MonSignals{2,1}{1,1},'.',MonSignals{2,1}{1,2}{i,1}),',');
    set_param(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/Monitor',num2str(temp+1)),'GotoTag',MonSignals{2,1}{1,2}{i,1},'Description',strcat(MonSignals{2,1}{1,2}{i,1},'-State'));
    temp = temp + 1;
end
for i = 1 : e
    add_block('Simulink/Signal Routing/Goto',strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/Mon',num2str(temp+1)),'Position',[1950 385-MonNum*30+30+temp*60 2050 415-MonNum*30+30+temp*60],'GotoTag',MonSignals{3,1}{1,2}{i,1});
    BusOut = strcat(BusOut,strcat(MonSignals{3,1}{1,1},'.',MonSignals{3,1}{1,2}{i,1}),',');
    set_param(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/Monitor',num2str(temp+1)),'GotoTag',MonSignals{3,1}{1,2}{i,1},'Description',strcat(MonSignals{3,1}{1,2}{i,1},'-LKA'));
    temp = temp + 1;
end
BusOut = BusOut(1:length(BusOut)-1);
set_param(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/LLBus'),'OutputSignals',BusOut);
for i = 1 : MonNum
    add_line(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'),strcat('LLBus/',num2str(i)),strcat('Mon',num2str(i),'/1'));
end
for i = temp+1 : 32
    set_param(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor/Monitor',num2str(i)),'GotoTag',strcat('Monitor',num2str(i)),'Description',strcat('Monitor',num2str(i)));
end
fprintf('4.����ɿ���ļ��й۲�ģ������\n');
%% 5.����ģ���еĹ۲����������ݿ��ļ��ź�
monxlspath = strcat(path,'\Tools\CANMaster');
fprintf('5.ȷ��Ŀ���ļ���Ŀ¼���С�CAN_Protocol_Raw.xlsx���ļ���ͬʱ���ļ�δ����\n');
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
%% 6.���ݹ۲������Ƹ������ݿ��ļ�
Monitor = find_system(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'),'SearchDepth',1,'BlockType','From');
MonitorNum = length(Monitor)-1;
dist = Monitor{2};
for i = 1:MonitorNum
    Monitor{i} = strcat(dist(1:length(dist)-1),num2str(i));
end
tag = {MonitorNum};
text = {MonitorNum};
for i = 1:MonitorNum
    tag(i) = get_param(Monitor(i),'GotoTag');
    text(i) = get_param(Monitor(i),'Description');
%     set_param(Monitor{i},'Description',strcat('Monitor',num2str(i)));
end
id = 1536;
varid = 45;
a = [];
for i = 1 : MonitorNum
    if contains(text(i),'-LKA')
        deviceid = '13';
    elseif contains(text(i),'-State')
        deviceid = '12';
    elseif contains(text(i),'-InP')
        deviceid = '11';
    else
        deviceid = '14';
    end
    addsignals = [strcat(tag(i),'_',num2str(i)),num2str(10),num2str(id+16*idivide(i-1,int32(4))),'0',num2str(varid+i),'1',num2str(7+mod(i-1,4)*16),'16','0','0.01',deviceid,'-','300','-300',text(i),'1'];
    Monxlstable = [Monxlstable;addsignals];
end
writetable(Monxlstable,strcat(monxlspath,'\CAN_Protocol.xls'));
fprintf('6.���Ĺ۲���������д���ļ���CAN_Protocol.xls��\n');
%% 7.���ݹ۲��������޸�dbc�ļ�
dbcfile = strcat(path,'\Documents\LKAS-Monitor.dbc');
newdbcfile = strcat(path,'\Documents\new-LKAS-Monitor.dbc');
dbcinifile = strcat(path,'\Documents\LKAS-Monitor.ini');
newdbcinifile = strcat(path,'\Documents\new-LKAS-Monitor.ini');
fid = fopen(newdbcfile,'wt');      %�½�һ���ļ�  
fpn = fopen(dbcfile, 'rt');           %���ĵ�  
i = 1;
while feof(fpn) ~= 1                %�����ж��ļ�ָ��p������ָ���ļ��е�λ�ã�������ļ�ĩ����������1�����򷵻�0  
    line = fgetl(fpn);            %��ȡ�ĵ���һ��   
    if line == -1
        break;
    end
    if contains(line," SG_ ")&&contains(line,' "Mon" ')&&(i <= MonitorNum)
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
fprintf('7.���ġ�%s���ļ��Ѹ���\n',dbcfile);
%% 8.����DBC�ļ����¹۲�ģ���CANPackģ��
CANpack = find_system(strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'),'MsgIDType','Standard (11-bit identifier)');
for i = 1:8
    set_param(CANpack{i},'DataFormat','CANdb specified signals');
    set_param(CANpack{i},'CANdbFile',dbcfile,'MsgList',strcat('Mon_',num2str(i)));
end
fprintf('8.���ġ�%s��ģ���Ѹ���\n',strcat(scriptfile,'/CAN Monitor (CANMon)/Monitor'));
save_system(scriptfile);
save_system(modelname);