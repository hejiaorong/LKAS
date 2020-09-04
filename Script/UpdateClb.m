eval('clear all');
eval('clc');
%% 1.打开模型并获取标定量名称,根据观测量名称更新数据库文件
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
    fprintf('2.您的目标*.slx文件是:【%s】\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
warning('off');
open_system(filename);
open_system(strcat(filename,'/Clb'));
Clb = find_system(strcat(filename,'/LLClb'),'SearchDepth',2,'BlockType','From');
ClbNum = size(Clb);
dist = Clb{1};

tag = {ClbNum(1)};
text = {ClbNum(1)};

for i = 1:ClbNum(1)
    tag(i) = get_param(Clb(i),'GotoTag');
    text(i) = get_param(Clb(i),'Description');

    add_block('Simulink/Signal Routing/Goto',strcat(filename,'/Clb/Clb',num2str(i)),'Position',[600+double(idivide(i-1,int32(10))*500) 200+double(mod(i-1,10))*50 800+double(idivide(i-1,int32(10))*500) 220+double(mod(i-1,10))*50]);
    set_param(strcat(filename,'/Clb/Clb',num2str(i)),'GotoTag',tag{i},'TagVisibility','global');
    add_line(strcat(filename,'/Clb'),strcat('Calibration',num2str(idivide(i-1,int32(10))+1),'/',num2str(mod(i-1,10)+1)),strcat('Clb',num2str(i),'/1'));

end




