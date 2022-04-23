function [gbkcheckflg,gbkcheckinfo] = Build_GBKCheck()
path = cd;
codefile = strcat(path,'\bin\LKAS_autosar_rtw\LKAS_component.arxml');
fpn = fopen(codefile, 'rt');           %打开文档  
i = 1;
cmout = false;
gbklog = {'line','index','line'};
while feof(fpn) ~= 1                %用于判断文件指针p在其所指的文件中的位置，如果到文件末，函数返回1，否则返回0  
    line = fgetl(fpn);            %获取文档第一行
    if line == -1
       break;
    end
    if contains(line,"<!--") 
        cmout = true;
    end
    if cmout~=1
        idx = int32(line)<=40869&int32(line)>=19968;
        count = sum(idx,'all');
        if count
           gbklog = cat(1,gbklog,{i,count,line});
        end
    end
    if contains(line,"-->")
    cmout = false;
    end
    i = i+1;
end  
fclose(fpn); 
[gbknum,~] = size(gbklog);
if gbknum>1
    gbkcheckflg = true;
    gbkcheckinfo = gbklog;
    disp(gbkcheckinfo);
else
    gbkcheckflg = false;
    gbkcheckinfo = {};
end