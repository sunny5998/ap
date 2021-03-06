clc;
clear all; 
close all;

x1 = [1,1,0,0];
x2 = [1,0,1,0];
x3=[1,0];
y= [0,0,0,0];
y2=[0,0];
wt = [2,2];

for i=1:1:4
    y(i)=wt(1)* x1(i) + wt(2)* x2(i);
end

%for AND gate
for i=1:1:4
    if y(i) >= 4
        yand(i)=1;
    else
        yand(i)=0;
    end;
end

%for OR gate
for i=1:1:4
    if y(i) >= 2
        yor(i)=1;
    else
        yor(i)=0;
    end;
end

%for NOT gate
for i=1:1:2
    y2(i)=wt(1)*x3(i);
end

for i=1:1:2
    if y2(i)<=0
        ynot(i)=1;
    else
        ynot(i)=0;
    end
end

%for XOR gate

for i=1:1:4
    if y(i)==2
        yxor(i)=1;
    else
        yxor(i)=0;
    end
end

%for NAND gate

for i=1:1:4
    if y(i)==4
        ynand(i)=0;
    else
        ynand(i)=1;
    end
end


display(y);
display(x1);
display(x2);
display(x3);
display(y2);
display(yand);
display(yor);
display(ynot);
display(yxor);
display(ynand);