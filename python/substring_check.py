#Check if substring found in string
#Command line: python substring_check.py [substring] [string]

import argparse

parser = argparse.ArgumentParser()
parser.add_argument('substring')
parser.add_argument('string')
args = parser.parse_args()

print (args.substring in args.string)
