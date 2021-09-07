# options(repos = c(CRAN = 'https://cloud.r-project.org/'))
# install.packages('ggplot2')
# install.packages('corrplot')

# install.packages('remotes')
# package_version(R.version) 
# install.packages("extrafont");

# remotes::install_version("Rttf2pt1", version = "1.3.8")
# extrafont::font_import()
# font_import()
# fonts();
# fonttable();
# font_import(pattern = "NanumGothic")

# install.packages("nortest")
# install.packages('caret')
require(nortest);
library(caret); 
library(extrafont); 
library(remotes);
library(ggplot2);
library(corrplot);

mape <- function(actual,pred){
  mape <- mean(abs((actual - pred)/actual))*100
  return (mape)
}

RMSE = function(m, o){
  sqrt(mean((m - o)^2))
}

options(max.print=1000000)

PP1 <- read.csv(file = "~/data/dataset/p3_1u_ai_202001-04__3min.csv");
PP1_DI <- read.csv(file =  "~/data/dataset/p3_1u_di_202001-04__3min.csv");
PP1_DI <- PP1_DI[,-c(1:2)];
PP1_DI <- PP1_DI[,c(3:17, 27:29)];
names(PP1_DI) <-  c("BFG연소여부_A1", "BFG연소여부_A2", "BFG연소여부_A3", "BFG연소여부_B1", "BFG연소여부_B2", "BFG연소여부_B3", "BFG연소여부_C1", "BFG연소여부_C2", "BFG연소여부_C3", "LDG연소여부_A1", "LDG연소여부_A2", "LDG연소여부_A3","LDG연소여부_B1", "LDG연소여부_B2", "LDG연소여부_B3", "COG연소여부_C1", "COG연소여부_C2", "COG연소여부_C3");
names(PP1) <-  c("NO",
                  "DATE",
                  "AIR_FLOW_오차",
                  "버너_개도_C1",
                  "버너_개도_C2",
                  "버너_개도_C3",
                  "BFG_유량",
                  "BFG_열량",
                  "COG_유량",
                  "COG_열량",
                  "CO_농도",
                  "BFG_압력",
                  "COG_압력",
                  "LDG_압력",
                  "급수_유량",
                  "저압증기_유량",
                  "BFG_유량_하단",
                  "BFG_유량_중단",
                  "BFG_유량_상단",
                  "TOTAL_AIR_FLOW",
                  "하_AIR_FLOW",
                  "중_AIR_FLOW",
                  "상_AIR_FLOW",
                  "LDG_열량",
                  "LDG_유량",
                  "Main_Steam_유량",
                  "NOX_농도",
                  "STACK_O2_농도_1열",
                  "O2_농도_2열",
                  "O2_농도_3열",
                  "진공도",
                  "Main_Steam_온도",
                  "BFG_온도",
                  "COG_온도",
                  "LDG_온도",
                  "GAH_공기_예열온도_입구",
                  "GAH_공기_예열온도_출구",
                  "BFG_예열온도_입구",
                  "BFG_예열온도_출구",
                  "원_단위"
);

PP1_DI$BFG <- PP1_DI$BFG연소여부_A1 + PP1_DI$BFG연소여부_A2 + PP1_DI$BFG연소여부_A3 + PP1_DI$BFG연소여부_B1 + PP1_DI$BFG연소여부_B2 + PP1_DI$BFG연소여부_B3 + PP1_DI$BFG연소여부_C1 + PP1_DI$BFG연소여부_C2 + PP1_DI$BFG연소여부_C3;

PP1_DI$A_BFG <- PP1_DI$BFG연소여부_A1 + PP1_DI$BFG연소여부_A2 + PP1_DI$BFG연소여부_A3;
PP1_DI <- subset(PP1_DI, select = -c(BFG연소여부_A1, BFG연소여부_A2, BFG연소여부_A3));

PP1_DI$B_BFG <- PP1_DI$BFG연소여부_B1 + PP1_DI$BFG연소여부_B2 + PP1_DI$BFG연소여부_B3;
PP1_DI <- subset(PP1_DI, select = -c(BFG연소여부_B1, BFG연소여부_B2, BFG연소여부_B3));

PP1_DI$C_BFG <- PP1_DI$BFG연소여부_C1 + PP1_DI$BFG연소여부_C2 + PP1_DI$BFG연소여부_C3;
PP1_DI <- subset(PP1_DI, select = -c(BFG연소여부_C1, BFG연소여부_C2, BFG연소여부_C3));

PP1_DI$LDG <- PP1_DI$LDG연소여부_A1 + PP1_DI$LDG연소여부_A2 + PP1_DI$LDG연소여부_A3 + PP1_DI$LDG연소여부_B1 + PP1_DI$LDG연소여부_B2 + PP1_DI$LDG연소여부_B3;
PP1_DI <- subset(PP1_DI, select = -c(LDG연소여부_A1, LDG연소여부_A2, LDG연소여부_A3, LDG연소여부_B1, LDG연소여부_B2, LDG연소여부_B3));

PP1_DI$COG <- PP1_DI$COG연소여부_C1 + PP1_DI$COG연소여부_C2 + PP1_DI$COG연소여부_C3;
PP1_DI <- subset(PP1_DI, select = -c(COG연소여부_C1, COG연소여부_C2, COG연소여부_C3));

#factor
PP1_DI$A_BFG <- as.factor(PP1_DI$A_BFG);
PP1_DI$B_BFG <- as.factor(PP1_DI$B_BFG);
PP1_DI$C_BFG <- as.factor(PP1_DI$C_BFG);
PP1_DI$LDG <- as.factor(PP1_DI$LDG);
PP1_DI$COG <- as.factor(PP1_DI$COG);

str(PP1_DI);
# 
# unique(PP1_DI$A_BFG);
# unique(PP1_DI$B_BFG);
# unique(PP1_DI$C_BFG);
# unique(PP1_DI$LDG);
# unique(PP1_DI$COG);
# 
# ggplot(PP1_DI, aes(x = A_BFG)) + geom_bar();
# ggplot(PP1_DI, aes(x = B_BFG)) + geom_bar();
# ggplot(PP1_DI, aes(x = C_BFG)) + geom_bar();
# ggplot(PP1_DI, aes(x = LDG)) + geom_bar();
# ggplot(PP1_DI, aes(x = COG)) + geom_bar();

PowerPlant <- PP1;
PowerPlant <- cbind(PowerPlant, PP1_DI);
PowerPlant <- PowerPlant[PowerPlant$원_단위 > 0 & PowerPlant$원_단위 < 5000,];


PowerPlant$Output <- ((PowerPlant$BFG_유량 * PowerPlant$BFG_열량) + (PowerPlant$LDG_유량 * PowerPlant$LDG_열량) +(PowerPlant$COG_유량 * PowerPlant$COG_열량))/2350;


#stop
# PowerPlant <- PowerPlant[PowerPlant$Output >= 60,]
PowerPlant <- PowerPlant[,-c(1:2)]
# PowerPlant <- PowerPlant[PowerPlant$COG_온도 >= 20,]
summary(PowerPlant$Output)
summary(PowerPlant$원_단위)


colSums(is.na(PowerPlant));
kmeans.PP1 <- kmeans(PowerPlant[,-c(39:43)], 3)

PowerPlant$cluster.kmeans <- kmeans.PP1$cluster  
PowerPlant$cluster.kmeans <- as.factor(PowerPlant$cluster.kmeans)
PowerPlant <- PowerPlant[PowerPlant$Output >= 50,]
# PowerPlant <- PowerPlant[PowerPlant$COG_온도 >= 20,]
is.factor(PowerPlant$cluster.kmeans)
summary(PowerPlant)

nTrain_kmeans <- caret::createDataPartition(y = PowerPlant$cluster.kmeans, p = 0.7, list = FALSE)

training_kmeans <- PowerPlant[nTrain_kmeans, ] 
testing_kmeans <- PowerPlant[-nTrain_kmeans, ]

control <- trainControl(method = "repeatedcv", number = 5, allowParallel = TRUE)    
modFit.rfcaret_kmeans <- caret::train(COG ~ ., method = "rf",data = training_kmeans, ntree = 100, trControl = control, number = 25);
modFit.rfcaret_kmeans$finalModel;
pred.test_kmeans = predict(modFit.rfcaret_kmeans, testing_kmeans);

# actuals_preds <- data.frame(cbind(actuals=testing_kmeans$원_단위, prediction=pred.test_kmeans))
# 
# correlation_accuracy <- cor(actuals_preds) 
# 
# correlation_accuracy

# 
# table_test <- table(factor(pred.test_kmeans, levels=min(pred.test_kmeans):max(pred.test_kmeans)), 
#                     factor(testing_kmeans$원_단위, levels=min(pred.test_kmeans):max(pred.test_kmeans)))

View(table_test)
mape(testing_kmeans$원_단위, pred.test_kmeans) * 100
RMSE(testing_kmeans$원_단위, pred.test_kmeans)
pred.test_kmeans <- as.factor(pred.test_kmeans)
confusionMatrix(pred.test_kmeans, testing_kmeans$COG)

