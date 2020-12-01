function [fcheckflg,fcheckinfo] = Build_FloatCheck()
path = cd;
codefile = strcat(path,'\bin\LKAS_autosar_rtw\LKAS.c');
fpn = fopen(codefile, 'rt');           %打开文档  
i = 1;
cmout = false;
doublelog = {'line','index','line'};
while feof(fpn) ~= 1                %用于判断文件指针p在其所指的文件中的位置，如果到文件末，函数返回1，否则返回0  
    line = fgetl(fpn);            %获取文档第一行   
    if line == -1
        break;
    end
    sprintf(line,i);
    if contains(line,"/*")
        cmout = true;
    end
    if contains(line,"*/")
        cmout = false;
    end
    if cmout
        i = i+1;
        continue
    end
%     if regexp(line,'for (', 'once')
%         i = i+1;
%         continue
%     end
    count = [];
    count = [count,regexp(line,'[Ff]loat64')];
    count = [count,regexp(line,'FLOAT64')];
%    count = [count,regexp(line,'[- ][0-9][; ]')];
    count = [count,regexp(line,'[0-9]\.[0-9][); ]')];
    count = [count,regexp(line,'[0-9]E[0-9][); ]')];
    count = [count,regexp(line,'[0-9]\.[0-9]E[0-9][); ]')];
    count = [count,regexp(line,'[0-9]E-[0-9][); ]')];
    count = [count,regexp(line,'[0-9]\.[0-9]E-[0-9][); ]')];
    if ~isempty(count)
        sprintf(line,i);
        doublelog = cat(1,doublelog,{i,count,line});
    end
    i = i+1;
end  
fclose(fpn); 
[doublenum,~] = size(doublelog);
if doublenum>1
    fcheckflg = true;
    fcheckinfo = doublelog;
else
    fcheckflg = false;
    fcheckinfo = {};
end