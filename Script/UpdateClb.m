eval('clear all');
eval('clc');
%% 1.��ģ�Ͳ���ȡ�궨������,���ݹ۲������Ƹ������ݿ��ļ�
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
    fprintf('2.����Ŀ��*.slx�ļ���:��%s��\n',getFileName);
end
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
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




