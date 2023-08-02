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
for rowOfCellObjects in sheet['A2':'A18956']:
  for cellObj in rowOfCellObjects:
    #Iterate through each cell in the range
    line = cellObj.value
    #regex to grab only emojis from captions
    regex = re.compile(r'(\u00a9|\u00ae|[\u2050-\u2099]|[\u2601-\u2605]|[\u2610-\u2660]|[\u2662-\u3000]|\ud83c[\ud000-\udfff]|\ud83d[\ud000-\udfff]|\ud83e[\ud000-\udfff])')
    onlyEmojis = regex.findall(line)
    #Convert emojis to text
    textonlyEmojis = emoji.demojize(onlyEmojis)
    #Regex to get rid of colons and seperate out emoji names into seperate cells
    final = re.findall(":+([^@][^#][^:]+):", textonlyEmojis)
    data.append(final)

#exports to excel
df = pd.DataFrame(data)
with pd.ExcelWriter('Data.xlsx', mode='a') as writer:
  df.to_excel(writer)
