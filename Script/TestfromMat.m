eval('clear all');
eval('clc');
%% 1.根据目录确定slx文件名称
path = cd;
getFileName=ls(strcat(pwd,'\*.slx')); %  *脚本和slx放在同一个文件夹该文件夹下有且只有一个slx文件
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
    fprintf('1.您的目标*.slx文件是:[%s]\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
load_system(filename);
open(getFileName);
sltest.harness.open('LKAS/LKAS/LL','LKAS_Harness');%打开test harness
getFileName1=ls(strcat(pwd,'\*.mat'));
FileNum = size(getFileName1);
if  isequal(getFileName1,'') % 防止选择空文件夹
    fprintf('当前目录下没有找到*.mat文件\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('当前目录下存在不止1个*.mat文件\n');
    eval('clear all');
    return;
else
    fprintf('1.您的目标*.mat文件是:[%s]\n',getFileName1);
end
load(getFileName1)；%将mat文件载入工作区
sim(('LKAS_Harness'));
runIDs = Simulink.sdi.getAllRunIDs;
runID = runIDs(end);
brakeRun = Simulink.sdi.getRun(runID);
run_DSRef = brakeRun.getDatasetRef;
run_DSRef.plot;%打开仿真信号查看器
