%# load data
load carsmall

ds = mat2dataset(meas);
ds(1:10,:)

%# construct predicting attributes and target class
vars = {'MPG' 'Cylinders' 'Horsepower' 'Model_Year'};
x = [MPG Cylinders Horsepower Model_Year];  %# mixed continous/discrete data
y = cellstr(Origin);                        %# class labels

%# train classification decision tree
t = classregtree(x, y, 'method','classification', 'names',vars, ...
                'categorical',[2 4], 'prune','off');
view(t)
