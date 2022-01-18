eval('clear all');
eval('clc');
%% 1.����Ŀ¼ȷ��slx�ļ�����
path = cd;
getFileName=ls(strcat(pwd,'\*.slx')); %  *�ű���slx����ͬһ���ļ��и��ļ���������ֻ��һ��slx�ļ�
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
polyflg = true;
warning('off');
rmpath('D:\ProgramFiles\MATLAB\toolbox\rtw\targets\asap2\asap2\CANape_user')
ModelSavePath = strcat(path,'\ModelSave');
binPath = strcat(path,'\bin');
try
    rmdir slprj s
catch
end
filename = getFileName(1:length(getFileName)-4);    %��ȡslx�ļ���
date1 = datestr(now,'yyyymmdd_HHMM');
date2 = datestr(now,'yyyymmdd');
slbuild(filename,'StandaloneRTWTarget','ForceTopModelBuild',true);
%% 2.��polyspace���д�����
if polyflg
    opts = polyspace.ModelLinkCodeProverOptions('C');
    opts.CodingRulesCodeMetrics.EnableMisraC3 = true; %ѡ�������Թ���
    opts.CodingRulesCodeMetrics.MisraC3Subset = 'all';
    opts.CodingRulesCodeMetrics.CodeMetrics = true;
    opts.MergedReporting.EnableReportGeneration = true; %���ɴ�����Ա���
    opts.MergedReporting.CodeProverReportTemplate = 'Developer';
    opts.MergedReporting.ReportOutputFormat = 'HTML';
 
    load_system(filename);
    prjfile = opts.generateProject(filename);  
    mlopts = pslinkoptions(filename);
    mlopts.EnablePrjConfigFile = true;   %ʹ�������������ɵ������ļ�
    mlopts.PrjConfigFile = prjfile;
    mlopts.ResultDir = strcat(binPath,'\',filename,'_CodeTest_',date1);
    mlopts.VerificationMode = 'BugFinder'; %ѡ��������ģʽ
    %mlopts.VerificationMode = 'CodeProver'; %ѡ��������ģʽ
    pslinkrun(filename, mlopts);  %���д�����
    save_system(filename);
end
%% 
close_system(filename);
newSWCfile = strcat(filename,'_AutoSave_DF_',date1);
getNewSWCName = strcat(newSWCfile,'.slx');
copyfile(getFileName,ModelSavePath);
eval(strcat('!rename',32,ModelSavePath,'\',getFileName,32,getNewSWCName));
zipfile = strcat(filename,'_Polyspace_',date2);
ziplist = {strcat(binPath,'\',filename,'_autosar_rtw')};
zip(strcat(zipfile,'.zip'),ziplist);
movefile(strcat(zipfile,'.zip'),ModelSavePath); 
proj = simulinkproject;
addFile(proj,strcat(ModelSavePath,'\',zipfile,'.zip'));
if polyflg
    zipfile1 = strcat(filename,'_CodeTest_',date1);
    ziplist1 = {strcat(binPath,'\',filename,'_CodeTest_',date1)};
    zip(strcat(zipfile1,'.zip'),ziplist1);
    movefile(strcat(zipfile1,'.zip'),ModelSavePath); 
    addFile(proj,strcat(ModelSavePath,'\',zipfile1,'.zip'));
    delete(strcat(filename,'_CodeTest_',date1));
    delete(strcat(path,'\',filename,'.psprj'));
end
addFile(proj,strcat(ModelSavePath,'\',getNewSWCName));
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