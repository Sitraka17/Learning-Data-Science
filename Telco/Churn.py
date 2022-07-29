## Importing packages
library(tidyverse) 
library(MASS)
library(car)
library(e1071)
library(caret)
library(cowplot)
library(caTools)
library(pROC)
library(ggcorrplot)


telco['Churn'].value_counts()

print(telco.groupby(['Churn']).mean())
