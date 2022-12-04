import requests
import json
import sys

day = sys.argv[1]
headers = json.load(open('./scripts/headers.json'))
res = requests.get('https://adventofcode.com/2022/day/{}/input'.format(day), headers=headers)

print(res.text)

f = open('d{}/build/in.txt'.format(day), 'w')
f.write(res.text)
f.close()
