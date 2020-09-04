%% 根据接口文档自动生成模型脚本
close('all');
if questdlg('此操作将关闭所以EXCEL和ACCESS程序，请确认！','警告','是','否','是')=='否'
    return;
end
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'EXCEL.EXE',32,'/T'));
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'MSACCESS.EXE',32,'/T'));
%% 1.根据模型中的观测量定义数据库文件信号
path = cd;
monxlspath = strcat(cd,'\Tools\CANMaster');
fprintf('1.确认目标文件夹目录下有【CAN_Protocol_Raw.xlsx】文件，同时该文件未被打开\n');
monxlsFileName=strcat(monxlspath,'\CAN_Protocol_Raw.xlsx'); %  *脚本和excel输入文件放在同一个文件夹该文件夹下有且只有一个文件xlsx文件

opts = spreadsheetImportOptions("NumVariables", 16);
opts.Sheet = 1; %excel 第几页名称
opts.DataRange = "A:P"; 
opts.VariableNames = ["var_Name","Period","CAN_ID","bSEND","VAR_ID","DataType","start_bit","bit_length","offset","bitResolution","device","Unit","max_Value","min_Value","Comment","byte_order"];
opts.VariableTypes = ["string", "string", "string", "string", "string","string", "string", "string", "string", "string","string", "string", "string", "string", "string", "string"];
opts = setvaropts(opts, [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], "WhitespaceRule", "preserve");
opts = setvaropts(opts, [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16], "EmptyFieldRule", "auto");
Monxlstable = readtable(monxlsFileName, opts, "UseExcel", false);    % 同一个文件夹相对路径 % 导入数据
clear  opts;    % 清除临时变量
Monxlstable(1,:)=[];
%% 2.根据观测量名称更新数据库文件
scriptpath = strcat(path,'\Script');
getFileName=ls(strcat(scriptpath,'\*.slx')); %  *脚本和slx放在同一个文件夹该文件夹下有且只有一个slx文件
FileNum = size(getFileName);
if  isequal(getFileName,'') % 防止选择空文件夹
    fprintf('当前目录下没有找到*.slx文件\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('当前目录下存在不止1个*.slx文件\n');
    eval('clear all');
    return;
else
    fprintf('2.您的目标*.slx文件是:【%s】\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
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
fprintf('2.您的观测量更新已写入文件【CAN_Protocol.xls】\n');
%% 3.根据观测量名称修改dbc文件
dbcfile = strcat(path,'\Documents\LKAS-Monitor.dbc');
newdbcfile = strcat(path,'\Documents\new-LKAS-Monitor.dbc');
dbcinifile = strcat(path,'\Documents\LKAS-Monitor.ini');
newdbcinifile = strcat(path,'\Documents\new-LKAS-Monitor.ini');
fid = fopen(newdbcfile,'wt');      %新建一个txt文件  
fpn = fopen(dbcfile, 'rt');           %打开文档  
i = 1;
while feof(fpn) ~= 1                %用于判断文件指针p在其所指的文件中的位置，如果到文件末，函数返回1，否则返回0  
    line = fgetl(fpn);            %获取文档第一行   
    if line == -1
        break;
    end
    if contains(line," SG_ ")&&contains(line,' "Mon" ')&&(i <= MonitorNum(1))
        new_str = regexpi(line,' ','split');
        new_str(3) = strcat(tag(i),num2str(i));
        newline = strjoin(new_str,' ');
        i = i + 1;
        fprintf(fid,'%s\n',newline);%新的字符串写入当新建文档中
    else
        fprintf(fid,'%s\n',line);%新的字符串写入当新建文档中
    end
end  
fclose(fid); 
fclose('all');
delete(dbcfile);
delete(dbcinifile);
delete(newdbcinifile);
eval(strcat('!rename',32,newdbcfile,32,'LKAS-Monitor.dbc'));
fprintf('3.您的【%s】文件已更新\n',dbcfile);
%% 4.根据DBC文件更新观测模块的CANPack模块
CANpack = find_system(strcat(filename,'/CAN Monitor (CANMon)/Monitor'),'MsgIDType','Standard (11-bit identifier)');
for i = 1:8
    set_param(CANpack{i},'DataFormat','CANdb specified signals');
    set_param(CANpack{i},'CANdbFile',dbcfile,'MsgList',strcat('Mon_',num2str(i)));
end
fprintf('4.您的【%s】模块已更新\n',strcat(filename,'/CAN Monitor (CANMon)/Monitor'));
save_system(filename);