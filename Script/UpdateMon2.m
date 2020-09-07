%% 根据接口文档自动生成模型脚本
close('all');
if questdlg('此操作将关闭所以EXCEL和ACCESS程序，请确认！','警告','是','否','是')=='否'
    return;
end
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'EXCEL.EXE',32,'/T'));
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'MSACCESS.EXE',32,'/T'));
%% 1.获取模型中的观测量配置
path = cd;
getModelName=ls(strcat(path,'\*.slx')); %  *脚本和slx放在同一个文件夹该文件夹下有且只有一个slx文件
FileNum = size(getModelName);
if  isequal(getModelName,'') % 防止选择空文件夹
    fprintf('当前目录下没有找到*.slx文件\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('当前目录下存在不止1个*.slx文件\n');
    eval('clear all');
    return;
else
    fprintf('1.您的目标*.slx文件是:【%s】\n',getModelName);
end
modelname = getModelName(1:length(getModelName)-4);    %获取slx文件名
warning('off');
open_system(modelname);
open_system(strcat(modelname,'/',modelname,'/LL/LLOn'));
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