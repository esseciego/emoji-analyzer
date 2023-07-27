import emoji
import re
import openpyxl

data = []
fname = 'Spreadsheet.xlsx'
wb = openpyxl.load_workbook(fname)
sheet = wb.get_sheet_by_name('50aTime')
for rowOfCellObjects in sheet['A1':'A14691']:
  for cellObj in rowOfCellObjects:
    line = emoji.demojize(cellObj.value)
    onlyEmojis = re.findall(":+([^:]+):",line)
    data.append(onlyEmojis)

# raw_data = emoji.demojize("🤔 🙈 me así, se 😌 ds 💕👭👙 hello 👩🏾‍🎓 emoji hello 👨‍👩‍👦‍👦 how are 😊 you today🙅🏽🙅🏽")
# onlyEmojis = re.findall(":+([^:]+):",raw_data)
#REGEX to extract emojis
#:+([^:]+):

for i in data:
  print(i)