clc;
clear all; 
close all;

% SIGMOID FUNCTION
x1=[-5,-4,-3,-2,-1,0,1,2,3,4,5];
y1=[0,0,0,0,0,0,0,0,0,0];
for i=1:1:11
    y1(i)=1/(1+exp(-x1(i)));
end

%TANH FUNCTION
x2 = -5:0.01:5; 
y2 = tanh(x2);

%LINEAR FUNCTION 
x3 = 0 : 50;
m = 2;
b = 0;
y3 = m*x3 + b;

%RELU
x4=[-5,-4,-3,-2,-1,0,1,2,3,4,5];
y4=[0,0,0,0,0,0,0,0,0,0];
for i=1:1:11
    y4(i)=max(0,x4(i));
end

%BINARY
x5=[-5,-4,-3,-2,-1,1,2,3,4,5];
y5=[0,0,0,0,0,0,0,0,0];
for i=1:1:10
    if x5(i) >= 0
        y5(i)=1;
    else
        y5(i)=0;
    end;
end

subplot(231)
plot(x1,y1)
title('Sigmoid')
grid on

subplot(232)
plot(x2,y2) 
title('Tanh')
grid on

subplot(233)
plot(x3,y3)
title('Linear')
grid on

subplot(234)
plot(x4,y4)
title('ReLU')
grid on

subplot(235)
plot(x5,y5)
title('BINARY')
grid on