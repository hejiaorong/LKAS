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
elseif questdlg('您将编译适用于东风控制器的程序，请您保存模型。是否继续？','编译确认','是','否','是')=='是'
    fprintf('1.您的目标*.slx文件是:[%s]\n',getFileName);
else
    return;
end
if questdlg('是否需要使用Polyspace进行代码检测？','Polyspace确认','是','否','否')=='是'
    polyflg = true;
else
    polyflg = false;
end
warning('off');
rmpath('D:\ProgramFiles\MATLAB\toolbox\rtw\targets\asap2\asap2\CANape_user')
ModelSavePath = strcat(path,'\ModelSave');
binPath = strcat(path,'\bin');
try
    rmdir slprj s
catch
end
filename = getFileName(1:length(getFileName)-4);    %获取slx文件名
date1 = datestr(now,'yyyymmdd_HHMM');
date2 = datestr(now,'yyyymmdd');
slbuild(filename,'StandaloneRTWTarget','ForceTopModelBuild',true);
%% 2.用polyspace进行代码检测
if polyflg
    opts = polyspace.ModelLinkCodeProverOptions('C');
    opts.CodingRulesCodeMetrics.EnableMisraC3 = true; %选择代码测试规则
    opts.CodingRulesCodeMetrics.MisraC3Subset = 'all';
    opts.CodingRulesCodeMetrics.CodeMetrics = true;
    opts.MergedReporting.EnableReportGeneration = true; %生成代码测试报告
    opts.MergedReporting.CodeProverReportTemplate = 'Developer';
    opts.MergedReporting.ReportOutputFormat = 'HTML';
 
    load_system(filename);
    prjfile = opts.generateProject(filename);  
    mlopts = pslinkoptions(filename);
    mlopts.EnablePrjConfigFile = true;   %使用以上配置生成的属性文件
    mlopts.PrjConfigFile = prjfile;
    mlopts.ResultDir = strcat(binPath,'\',filename,'_CodeTest_',date1);
    %mlopts.VerificationMode = 'BugFinder'; %选择代码测试模式
    mlopts.VerificationMode = 'CodeProver'; %选择代码测试模式
    pslinkrun(filename, mlopts);  %运行代码检测
    save_system(filename);
end
%% 
close_system(filename);
newSWCfile = strcat(filename,'_AutoSave_DF_',date1);
getNewSWCName = strcat(newSWCfile,'.slx');
copyfile(getFileName,ModelSavePath);
eval(strcat('!rename',32,ModelSavePath,'\',getFileName,32,getNewSWCName));
zipfile = strcat(filename,'_',date2);
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
[GBKcheckflg,GBKcheckinfo] = Build_GBKCheck();
if Fcheckflg
    fprintf(2,'【警告】您生成的代码含有double数据类型，请检查！\n');
    msgbox('您生成的代码含有double数据类型', '警告','error');
    eval('Fcheckinfo');
end
if GBKcheckflg
    fprintf(2,'【警告】您生成的LKAS_component.arxml中含有GBK字符，请检查！\n');
    msgbox('您生成的LKAS_component.arxml中含有GBK字符', '警告','error');
    eval('GBKcheckinfo');
end
if ~Fcheckflg && ~GBKcheckflg
    fprintf('【成功】您生成的代码已打包\n');
    eval('clear all');
end