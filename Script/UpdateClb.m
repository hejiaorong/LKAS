eval('clear all');
eval('clc');
close('all');
if questdlg('此操作将关闭所以EXCEL和ACCESS程序，请确认！','警告','是','否','是')=='否'
    return;
end
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'EXCEL.EXE',32,'/T'));
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'MSACCESS.EXE',32,'/T'));
%% 1.打开模型并获取标定量名称
path = cd;
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
    fprintf('1.您的目标*.slx文件是:【%s】\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
warning('off');
load_system(filename);
load_system(strcat(filename,'/Clb'));
Clb = find_system(strcat(filename,'/LLClb'),'SearchDepth',2,'BlockType','From');
ClbNum = size(Clb);
dist = Clb{1};
%% 2.根据标定量设置构造标定数据表
path = cd;
clbxlspath = strcat(cd,'\Tools\CANMaster');
fprintf('2.确认目标文件夹目录下有【CAN_Calibration.xls】文件，同时该文件未被打开\n');
clbxlsFileName=strcat(clbxlspath,'\CAN_Calibration.xls'); %  *脚本和excel输入文件放在同一个文件夹该文件夹下有且只有一个文件xlsx文件
opts = spreadsheetImportOptions("NumVariables", 5);
opts.Sheet = 1; %excel 第几页名称
opts.DataRange = "A1:E1"; 
opts.VariableNames = ["type","name","value","comment","sort"];
opts.VariableTypes = ["string", "string", "string", "string", "string"];
opts = setvaropts(opts, [1,2,3,4,5], "WhitespaceRule", "preserve");
opts = setvaropts(opts, [1,2,3,4,5], "EmptyFieldRule", "auto");
Clbxlstable = readtable(clbxlsFileName, opts, "UseExcel", false);    % 同一个文件夹相对路径 % 导入数据
clear  opts;    % 清除临时变量

mdlWks = get_param(filename,'ModelWorkspace');

tag = {ClbNum(1)};
text = {ClbNum(1)};
type = {ClbNum(1)};
value = {ClbNum(1)};
clbnum = 0;
num = 1;
for i = 1:100
    if i<= ClbNum(1)
        str = get_param(Clb(i),'GotoTag');
        str = str{1};
        if length(str)>=10
            tag(num) = get_param(Clb(i),'GotoTag');
            text(num) = get_param(Clb(i),'Description');
            set_param(strcat(filename,'/Clb/Clb',num2str(num)),'GotoTag',tag{num},'TagVisibility','global','Description',text{num});
            new_str = regexpi(Clb{i},'/','split');
            type(num) = new_str(3);
            if isempty(text{num})
                text{num} = 'none';
            end
            v = getVariable(mdlWks,tag{num});
            value{num} = num2str(v.Value);
            addclb = cell(1,5);
            addclb =  [type(num),tag(num),value(num),text(num),num2str(num)];
            Clbxlstable = [Clbxlstable;addclb];
            num = num + 1;
            clbnum = clbnum+1;
        end
    else
        set_param(strcat(filename,'/Clb/Clb',num2str(num)),'GotoTag',strcat('empty',num2str(num)),'TagVisibility','global');
        addclb =  [{''},{''},{''},{''},{''}];
        Clbxlstable = [Clbxlstable;addclb];
        num = num + 1;
    end
    if num > 30
        break
    end
end
%% 3.写入标定数据表
xlswrite(strcat(clbxlspath,'\CAN_Calibration.xls'),table2array(Clbxlstable));
fprintf('3.您的标定量更新已写入文件【CAN_Calibration.xls】\n');
save_system(filename);

