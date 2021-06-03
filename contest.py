from bs4 import BeautifulSoup
from requests import get
from pprint import pprint
from pathlib import Path
import sys
import re
import os

resp = get(f'https://codeforces.com/contest/{sys.argv[1]}/problems')
soup = BeautifulSoup(resp.text, "html.parser")

permitted = True

if sys.argv[1] in os.listdir('./codeforces'):
    print('Are You sure [You] want to OVERWRITE [Y]/n: ', end='')
    user = input()
    if user == 'n':
        permitted = False
    else:
        permitted = True
        os.system(f'rm -rf ./codeforces/{sys.argv[1]}')

if permitted:
    path = f'./codeforces/{sys.argv[1]}'
    os.system(f'mkdir {path}')

    problems = soup.find_all('div', class_='problem-statement')

    for i in problems:
        _id, name = i.find('div', class_='title').text.split('. ')
        name = name.strip(' ').replace(' ', '_')

        sub_path = f'{path}/{_id}'
        os.system(f'mkdir {sub_path}')
        os.system(f'cp ./tmp.cpp {sub_path}/{name}.cpp')

        AllCases, SampleCases = i.find_all('pre'), []
        for i in range(0, len(AllCases), 2):
            SampleCases.append([AllCases[i], AllCases[i+1]])

        CaseNum = 0
        for Case in SampleCases:
            Input, Output = Case[0].text, Case[1].text
            CaseNum += 1

            with open(f'{sub_path}/Input{CaseNum}', 'w') as f:
                Input = Input.strip().strip('\n')
                f.write(Input)

            with open(f'{sub_path}/Output{CaseNum}', 'w') as f:
                Output = Output.strip().strip('\n')
                f.write(Output)

        # testScript = ''
        # with open('test.cpp', 'w') as f:
        #     f.write(testScript)
        # os.system('g++ -O3 test.cpp -o test')
        # os.system(f'mv test {sub_path}/test')
        # os.system(f'rm test.cpp')
