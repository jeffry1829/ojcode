#encoding=utf-8  
import numpy as np
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit
import pandas as pd  

#自定義函式 e指數形式
def func(x, a, b, c, d):
    return a*np.power((np.sinc(b*(x-c))),2)+d
    #return a*np.exp(-(x-b)**2/c)+d

#匯入資料及x、y散點座標
data = pd.read_csv("data.csv")
print(data)
print(data.shape)    
print(data.head(5)) #顯示前5行資料
x = data['pos']
y = data['avg']
print(x)
print(y)

#非線性最小二乘法擬合
popt, pcov = curve_fit(func, x, y, maxfev=100000)

#獲取popt裡面是擬合係數
a = popt[0] 
b = popt[1]
c = popt[2] 
d = popt[3]

yvals = func(x,a,b,c,d) #擬合y值
residuals = y- func(x, *popt)
ss_res = np.sum(residuals**2)
ss_tot = np.sum((y-np.mean(y))**2)
r_squared = 1 - (ss_res / ss_tot)

print(u'係數a:', a)
print(u'係數b:', b)
print(u'係數c:', c)
print(u'係數d:', d)
print(u'R^2:', r_squared)

#繪圖
plot1 = plt.plot(x, y, 's',label='original values')
plot2 = plt.plot(x, yvals, 'r',label='polyfit values')
plt.xlabel('x')
plt.ylabel('y')
plt.legend(loc=4) #指定legend的位置右下角
plt.title(u'NEAR Normal dist')
plt.savefig(u'NEAR Normal dist.png')
plt.show()