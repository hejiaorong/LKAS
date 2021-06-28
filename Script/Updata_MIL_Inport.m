[~,spacename,~] = xlsread('MIL_Inport.xlsx',1,'A:A');
[~,spacedata,~]=xlsread('MIL_Inport.xlsx',1,'B:B');
PortConnec = get_param('LKAS_MIL_G59/SignalBusCreator','PortConnectivity');
for j=1:length(spacedata)
    myblock = ['LKAS_MIL_G59/',spacename{j}];
    blockname = spacedata{j};
    add_block('simulink/Sources/From Workspace',myblock,'Variablename',blockname);
    PortPstn = PortConnec(j).Position;
    add_line('LKAS_MIL_G59/',[spacename{j},'/1'],['SignalBusCreator/',num2str(j)]);
    set_param(myblock,'Position',[PortPstn(1)-435,PortPstn(2)-12,PortPstn(1)-135,PortPstn(2)+12]);
end


