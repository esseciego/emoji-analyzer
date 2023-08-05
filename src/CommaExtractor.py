import emoji
import re
import openpyxl
import pandas as pd


data = []
#Reads in data from excel
fname = 'Spreadsheet.xlsx'
wb = openpyxl.load_workbook(fname)
sheet = wb.get_sheet_by_name('50aTime')

#https://www.regextester.com/106421
for rowOfCellObjects in sheet['A2':'A23761']:
  for cellObj in rowOfCellObjects:
    #Iterate through each cell in the range
    line = cellObj.value
    #regex to delete all lines
    final = line.replace('\n', '')
    actual = final.replace(',','')
    data.append(actual)

#exports to excel
df = pd.DataFrame(data)
with pd.ExcelWriter('Data.xlsx', mode='a') as writer:
  df.to_excel(writer)
