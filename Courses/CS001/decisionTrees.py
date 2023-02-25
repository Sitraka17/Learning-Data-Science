#A decision tree is a sequence of yes/no questions that help the computer decide what to output.

from sklearn import tree
X = [[0, 0], [1, 1]]
Y = [0, 1]
clf = tree.DecisionTreeClassifier()
clf = clf.fit(X, Y)


###" The random forest is a classification algorithm consisting of many decisions trees. 
#It uses bagging and feature randomness when building each individual tree to try to create an uncorrelated forest of trees 
#whose prediction by committee is more accurate than that of any individual tree.
