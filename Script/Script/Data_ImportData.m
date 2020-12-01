eval('clear all');
eval('clc');
%将数据加载到工作区
warning('off');
try
    [filename,filepath]=uigetfile('*.mat','打开文件');
    load(strcat(filepath,filename));
    fprintf('1.[%s]已加载到工作区；\n',filename);
catch
    clear('filename','filepath');
    return;
end
%读取加载的变量，判断变量中是否有PSA1_CAN和Sensor_CAN参数
Data_Process;