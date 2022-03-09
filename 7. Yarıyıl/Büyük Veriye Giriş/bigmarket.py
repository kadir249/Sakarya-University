from numpy.core.fromnumeric import size
import pandas as pd
import numpy as np
import seaborn as sb
import matplotlib.pyplot as plt 
from matplotlib.pyplot import figure
from scipy import stats
import missingno as msno


# Adım 1
df = pd.read_csv("./train.csv")
# print(df)

# Adım 2
# msno.matrix(df)
# plt.show()

# Adım 3
# df.hist(edgecolor='black', linewidth=1.2, figsize=(20, 20))
# plt.show()

# Adım 4
# print(df["Item_Identifier"])

# Adım 5
for i in range(len(df)):
    df.loc[i , "Item_Code"] = df.loc[i,"Item_Identifier"][:2]
# print(df["Item_Code"])

# Adım 6
# df.info()

# Adım 7
df = df.drop(["Item_Identifier"] , axis = 1)
# print(df)

# Adım 8
# print(df["Item_Code"].value_counts())

# sb.countplot(df["Item_Code"])
# plt.grid()
# plt.show()

# Adım 9
# plt.scatter(df["Item_Weight"], df["Item_Outlet_Sales"])
# plt.show()

# Adım 10
# sb.boxplot(x = df["Item_Weight"])
# plt.grid()
# print(df["Item_Weight"].median())

# Adım 11
# sb.distplot(df["Item_Weight"].dropna())
# print("Kurtosis: " + str(df["Item_Weight"].kurt()))
# print("Skewness: " + str(df["Item_Weight"].skew()))
# plt.show()

# Adım 12
# print(df["Item_Weight"].isna().sum())
df["Item_Weight"].fillna(df["Item_Weight"].mean() ,  inplace = True)
# print(df["Item_Weight"].isna().sum())

# Adım 13
# sb.distplot(df["Item_Weight"].dropna())
# plt.show()
# print("Kurtosis: " + str(df["Item_Weight"].kurt()))
# print("Skewness: " + str(df["Item_Weight"].skew()))

# Adım 14
# print(df["Item_Fat_Content"].value_counts())

# Adım 15
# plt.figure(figsize=(10,8))
# sb.heatmap(df.corr(), annot=True, cmap="RdYlGn", annot_kws={"size":15})
# plt.show()

# Adım 16
# sb.countplot(df["Item_Fat_Content"] , hue = df["Outlet_Size"])
# plt.show()

# Adım 17
fat = {
    "Low Fat":"Low Fat","Regular":"Regular","low fat":"Low Fat","LF":"Low Fat","reg":"Regular"
}
df.loc[: , "Item_Fat_Content"] = df.loc[: , "Item_Fat_Content"].map(fat)

# sb.countplot(x = df["Item_Fat_Content"] , hue = df["Outlet_Size"])
# print(df["Item_Fat_Content"].value_counts())
# plt.show()

# Adım 18
cat = {
    "Low Fat": 1,"Regular":0
}
df.loc[: , "Item_Fat_Content"] = df.loc[: , "Item_Fat_Content"].map(cat)
df.corr()
# print(df.corr())

# Adım 19
# print(df["Item_Visibility"])

# Adım 20
# sb.distplot(df["Item_Visibility"])
# plt.show()
# print("Skewness: " + str(df["Item_Visibility"].skew()))

# Adım 21
# sb.boxplot(x = df["Item_Visibility"])
# plt.show()

# Adım 22
cols = "Item_Visibility"
high = 0.18
low = 0.0
df = df[(df[cols] > low) & (df[cols] < high)]
# sb.boxplot(x = df["Item_Visibility"])
# plt.show()

# Adım 23
# sb.distplot(df["Item_Visibility"])
# plt.show()
# print("Skewness: " + str(df["Item_Visibility"].skew()))

# Adım 24
df["Item_Visibility"] = np.log10(df["Item_Visibility"])
# print(df["Item_Visibility"])

# Adım 25
# sb.distplot(df["Item_Visibility"])
# plt.show()
# print("Skewness: "+ str(df["Item_Visibility"].skew()))

# Adım 26
# print(df.corr())

# Adım 27
# print(df["Item_Type"])

# Adım 28
# print(df["Item_Type"].value_counts())
# sb.countplot(x = df["Item_Type"])
# plt.xticks(rotation = 90)
# plt.show()

# Adım 29
food = {
    "Household": "Others","Frozen Foods":"Snack Foods" ,"Dairy":"Snack Foods", "Canned" : "Snack Foods", "Soft Drinks":"Drinks",
  "Hard Drinks":"Drinks"  ,"Starchy Foods":"Baking Goods","Breads":"Baking Goods","Meat":"Seafood","Breakfast":"Fruits and Vegetables",
    "Starchy Foods":"Baking Goods","Fruits and Vegetables":"Fruits and Vegetables","Snack Foods":"Snack Foods","Baking Goods":"Baking Goods",
    "Health and Hygiene":"Health and Hygiene","Seafood":"Seafood","Others":"Others",
}

df.loc[: , "Item_Type"] = df.loc[: , "Item_Type"].map(food)

# print(df["Item_Type"].value_counts())
# sb.countplot(x = df["Item_Type"])
# plt.xticks(rotation = 90)
# plt.grid()
# plt.show()

# Adım 30
encode = {
    "Snack Foods":7 ,"Fruits and Vegetables":6,"Others":5,"Baking Goods":4,"Drinks":3,"Health and Hygiene":2,"Seafood":1
}

df.loc[: , "Item_Type"] = df.loc[: , "Item_Type"].map(encode)

# print(df["Item_Type"].value_counts())
# sb.countplot(x = df["Item_Type"])
# plt.xticks(rotation = 90)
# plt.grid()
# plt.show()

# Adım 31
# sb.pairplot(df)
# plt.show()

# Adım 32
# sb.boxplot(df["Item_Type"])
# plt.show()

# Adım 33
# print(df)

# Adım 34
df["Item_MRP"].describe()
# print(df["Item_MRP"].describe())

# Adım 35
# sb.distplot(df["Item_MRP"])
# print("Kurtosis: " , df["Item_MRP"].kurt())
# print("Skewness: ", df["Item_MRP"].skew())
# plt.grid()
# plt.show()

# Adım 36
# sb.boxplot(df["Item_MRP"])
# plt.show()

# Adım 37
# print("Co-relation of sales and mrp is :",stats.pearsonr(df["Item_Outlet_Sales"] , df["Item_MRP"])[0])

# Adım 38
# plt.scatter(df["Item_MRP"],df["Item_Outlet_Sales"])
# plt.show()

# Adım 39
# print(df["Outlet_Identifier"])

# Adım 40
df = df.drop(["Outlet_Identifier"] , axis =1)
# print(df["Outlet_Establishment_Year"])

# Adım 41
# plt.hist(df["Outlet_Establishment_Year"])
# plt.grid()
# plt.show()

# Adım 42
# print("Co-relation of sales and mrp is :",stats.pearsonr(df["Item_Outlet_Sales"] , df["Outlet_Establishment_Year"])[0])

# Adım 43
# sb.heatmap(df.corr() , cmap="RdYlGn" , annot =True)
# plt.show()

# Adım 44
# sb.boxplot(df["Outlet_Establishment_Year"])
# plt.show()

# Adım 45
# sb.countplot(df["Outlet_Establishment_Year"] , hue = df["Outlet_Size"])
# plt.show()

# Adım 46
# print(df)

# Adım 47
df["Outlet_Size"].value_counts()
# sb.countplot(df["Outlet_Size"])
# plt.show()

# Adım 48
# print(df["Outlet_Size"].isna().sum())

# Adım 49
df["Outlet_Size"].fillna(value = "High" , inplace = True)
# sb.countplot(df["Outlet_Size"] , hue = df["Item_Type"])
# plt.grid()
# plt.show()

# Adım 50
out = {
    "Medium":2 , "Small":1,"High":3
}

df.loc[: , "Outlet_Size"] = df.loc[: , "Outlet_Size"].map(out) 
# print(df.corr())

# Adım 51
# sb.countplot(df["Outlet_Size"] , hue = df["Item_Fat_Content"])
# plt.grid()
# plt.show()

# Adım 52
# print(df["Outlet_Location_Type"].value_counts())
# sb.countplot(x = df["Outlet_Location_Type"])
# plt.show()

# Adım 53
# sb.countplot(x = df["Outlet_Location_Type"] , hue = df["Outlet_Size"] )
# plt.show()

# Adım 54
mapp = {
    "Tier 3" : 3 , "Tier 2":1 , "Tier 1":2
}
df.loc[: , "Outlet_Location_Type"] = df.loc[: , "Outlet_Location_Type"].map(mapp)

# sb.countplot(x = df["Outlet_Location_Type"] , hue = df["Outlet_Size"] )
# plt.show()

# Adım 55
# print(df.corr())

# Adım 56
# sb.countplot(df["Outlet_Location_Type"] , hue = df["Outlet_Establishment_Year"] )
# plt.show()

# Adım 57
# print(df)

# Adım 58
# print(df["Outlet_Type"].value_counts())
# sb.countplot(x = df["Outlet_Type"])
# plt.xticks(rotation = 90)
# plt.grid()
# plt.show()

# Adım 59
# sb.countplot(x = df["Outlet_Type"] , hue = df["Outlet_Location_Type"])
# plt.xticks(rotation = 90)
# plt.show()

# Adım 60
# sb.countplot(x = df["Outlet_Type"] , hue = df["Outlet_Establishment_Year"])
# plt.xticks(rotation = 90)
# plt.show()

# Adım 61
types = {"Supermarket Type1":4 , "Supermarket Type2":3 , "Supermarket Type3":2 , "Grocery Store":1
    
}
df.loc[: , "Outlet_Type"] = df.loc[: , "Outlet_Type"].map(types)
# print(df)

# Adım 62
# print(df.corr())

# Adım 63
# print(df["Item_Code"])

# Adım 64
# sb.countplot(x = df["Item_Code"])
# plt.show()

# Adım 65
types = {"FD":3 , "DR":1 , "NC":2    
}
df.loc[: , "Item_Code"] = df.loc[: , "Item_Code"].map(types)
# sb.boxplot(x = df["Item_Code"])
# plt.show()

# Adım 66
print(df.corr())