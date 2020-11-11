path = cd;
codefile = strcat(path,'\bin\LKAS_autosar_rtw\LKAS.c');
fpn = fopen(codefile, 'rt');           %打开文档  
i = 1;
cmout = false;
while feof(fpn) ~= 1                %用于判断文件指针p在其所指的文件中的位置，如果到文件末，函数返回1，否则返回0  
    line = fgetl(fpn);            %获取文档第一行   
    if line == -1
        break;
    end
    if contains(line,"/*")
        cmout = true;
    end
    if contains(line,"*/")
        cmout = false;
    end
    if cmout == true
        i = i+1;
        continue
    end
    count = [];
    count = [count,regexp(line,'[Ff]loat64')];
    count = [count,regexp(line,'FLOAT64')];
    count = [count,regexp(line,'[- ][0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]\.[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]E[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]\.[0-9]E[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]E-[0-9][; ]')];
    count = [count,regexp(line,'[- ][0-9]\.[0-9]E-[0-9][; ]')];


    if contains(line,"float64")||contains(line,'FLOAT64')&&(i <= MonitorNum)
        new_str = regexpi(line,' ','split');
        new_str(3) = strcat('M',num2str(i+100),'_',tag(i));
        newline = strjoin(new_str,' ');
        i = i + 1;
        fprintf(fid,'%s\n',newline);%新的字符串写入当新建文档中
    else
        fprintf(fid,'%s\n',line);%新的字符串写入当新建文档中
    end
end  
fclose(fid); 
fclose('all');