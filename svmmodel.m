clc;
close all;
clear all;


load fisheriris
data = [meas(:,1), meas(:,2)];
groups = ismember(species,'setosa');
[train, test] = crossvalind('holdOut',groups);
cp = classperf(groups);
svmStruct = svmtrain(data(train,:),groups(train),'showplot',true);

title(sprintf('Kernel Function: %s',...
              func2str(svmStruct.KernelFunction)),...
              'interpreter','none');
          
classes = svmclassify(svmStruct,data(test,:),'showplot',true);  

classperf(cp,classes,test);
cp.CorrectRate

svmStruct = svmtrain(data(train,:),groups(train),...
                     'showplot',true,'boxconstraint',1e6);
                 
classes = svmclassify(svmStruct,data(test,:),'showplot',true);

classperf(cp,classes,test);
cp.CorrectRate

