eval('clear all');
eval('clc');
%% 1.����Ŀ¼ȷ��slx�ļ�����
path = cd;
getFileName=ls(strcat(pwd,'\DFL\*.slx')); %  *�ű���slx����ͬһ���ļ��и��ļ���������ֻ��һ��slx�ļ�
FileNum = size(getFileName);
if  isequal(getFileName,'') % ��ֹѡ����ļ���
    fprintf('��ǰĿ¼��û���ҵ�*.slx�ļ�\n');
    eval('clear all');
    return;
elseif  FileNum ~= 1
    fprintf('��ǰĿ¼�´��ڲ�ֹ1��*.slx�ļ�\n');
    eval('clear all');
    return;
elseif questdlg('�������������ڶ���������ĳ�����������ģ�͡��Ƿ������','����ȷ��','��','��','��')=='��'
    fprintf('1.����Ŀ��*.slx�ļ���:[%s]\n',getFileName);
else
    return;
end
warning('off');
ModelSavePath = strcat(path,'\ModelSave');
binPath = strcat(path,'\bin');
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
movefile(strcat(pwd,'\LKAS.slx'),strcat(pwd,'\LKAS.slx.bak'))
movefile(strcat(pwd,'\DFL\',getFileName),strcat(pwd,'\DFL\','LKAS.slx'))
slbuild('LKAS','StandaloneRTWTarget','ForceTopModelBuild',true)
close_system('LKAS');
movefile(strcat(pwd,'\DFL\','LKAS.slx'),strcat(pwd,'\DFL\',getFileName))
movefile(strcat(pwd,'\LKAS.slx.bak'),strcat(pwd,'\LKAS.slx'))
zipfile = strcat(filename,'_',datestr(now,'yyyymmdd'));
ziplist = {strcat(binPath,'\','LKAS','_autosar_rtw')};
zip(strcat(zipfile,'.zip'),ziplist);
movefile(strcat(zipfile,'.zip'),ModelSavePath); 
proj = simulinkproject;
addFile(proj,strcat(ModelSavePath,'\',zipfile,'.zip'));
delete(strcat(filename,'.slxc'));
delete(strcat(filename,'_autosar_rtw'));
eval('clear all');
[Fcheckflg,Fcheckinfo] = Build_FloatCheck();
if Fcheckflg
    fprintf(2,'�����桿�����ɵĴ��뺬��double�������ͣ����飡\n');
    msgbox('�����ɵĴ��뺬��double��������', '����','error');
    eval('Fcheckinfo');
else
    fprintf('���ɹ��������ɵĴ����Ѵ��\n');
    eval('clear all');
end