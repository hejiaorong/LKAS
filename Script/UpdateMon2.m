%% ���ݽӿ��ĵ��Զ�����ģ�ͽű�
close('all');
if questdlg('�˲������ر�����EXCEL��ACCESS������ȷ�ϣ�','����','��','��','��')=='��'
    return;
end
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'EXCEL.EXE',32,'/T'));
eval(strcat('!TASKKILL',32,'/F',32,'/IM',32,'MSACCESS.EXE',32,'/T'));
%% 1.��ȡģ���еĹ۲�������
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
    fprintf('1.����Ŀ��*.slx�ļ���:��%s��\n',getModelName);
end
modelname = getModelName(1:length(getModelName)-4);    %��ȡslx�ļ���
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