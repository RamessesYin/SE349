#coding:utf-8
import csv
import re
from random import randrange

Tag={}
Person={}
cnt=0

with open('data_new.csv', 'rb') as csvfile:
	reader = csv.reader(csvfile)
	for row in reader:
		name= row[8]
		text=row[2]
		#print text
		#text=text.decode("utf-8")
		if name=='#NAME?':
			continue
		#如果有标签的话，统计标签，有可能有重复标签
		if '#' in text:
			tags=[]
			if name in Person:
				tags=Person[name]
			for m in re.finditer(r"#[^#]+#", text):
				t=m.group(0)
				if t not in Tag:
					Tag[t]=cnt
					cnt+=1
				if Tag[t] not in tags:
					tags.append(Tag[t])
			Person[name]=tags

with open('input.csv', 'wb') as csvfile2:	
	writer = csv.writer(csvfile2, delimiter=' ')	
	i=0
	for key in Person:
		tags=Person[key]
		if len(tags)<3:
			continue
		out=randrange(0,len(tags))
		while len(tags)<4:
			tags.append(0)
		tags[out],tags[3]=tags[3],tags[out]
		tags=tags[0:4]
		for n in range(4):
			tags[n]=(tags[n]/float(cnt))**0.5
		writer.writerow(tags)
		i+=1
		if i==10000:
			break


with open('tags.csv', 'wb') as csvfile3:	
	writer = csv.writer(csvfile3, delimiter=' ')
	for key in Tag:
		writer.writerow([key])




