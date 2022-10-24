#Halim Abraham Hamanoiel Galindo A0176137
#Sergio Gutierrez A01769367
import re

XS = ['as', 'do', 'fn', 'if', 'in', 'is', 'or']

S = ['and', 'def', 'del', 'for', 'int', 'new', 
'not', 'try', 'use', 'var', 'xor']

M = ['auto', 'case', 'char', 'echo', 'elif', 'else', 'enum', 
'exec', 'from', 'goto', 'list', 'long', 'pass', 'void', 'with', 'open', 'write']

L = ['break', 'catch', 'class', 'clone', 'const', 'empty', 'endif', 'final', 
'float', 'isset', 'print', 'raise', 'short', 'throw', 'trait', 'union', 
'while', 'yield']

XL = ['assert', 'double', 'elseif', 'endfor', 'except', 'extern', 'global', 'import', 
'lambda', 'public', 'return', 'signed', 'sizeof', 'static', 'struct', 'switch']

XXL = ['abstract', 'callable', 'continue', 'declare', 'default', 'enddeclare', 'endforeach', 
'endswitch', 'extends', 'finally', 'foreach', 'function', 'implements', 'include', 
'include_once', 'instanceof', 'insteadof', 'interface', 'namespace', 'private', 'protected', 
'register', 'require', 'require_once', 'typedef', 'unsigned', 'volatile', 'yield from']

RESERVED = XS+S+M+L+XL+XXL

sign = [";", "|", "%", "~", "[", "]","(",")","{",
        "}", ".", ",", "!", "&", "?"]
arithmetic = ["/","*","-","+"]

rewrite = ''
line_lst = []
RES_SIZE = len(RESERVED)
header = '<!DOCTYPE html>\n<html>\n<head>\n<link rel=stylesheet type="text/css" href="style.css">\n</head>\n<body>\n'

with open('code.txt','r') as r:
    with open('output.html','a+') as w:
        w.write(header)
        while True:
            original = r.readline()
            line = original
            is_between_curly = re.findall(r'\(.*?\)',original)
            is_between_quotes = re.findall(r'\".*?\"',original)
            is_between_squotes = re.findall(r'\'.*?\'',original)
            if original.find(':'):
                line = line.replace(':','<pre style="color:purple;">'+':'+'</pre>')
            for char in original:
                if char in sign:
                    line = line.replace(char,'<pre style="color:purple;">'+char+'</pre>')
                elif char in arithmetic:
                    line = line.replace(char,'<pre style="color:yellow;">'+char+'</pre>')
            digit = re.findall(r'[0-9]+',line)
            if digit:
                for integer in digit:
                    if int(integer) not in is_between_quotes:
                        line = re.sub(r'\b'+integer+r'\b','<pre style="color:green;">'+integer+'</pre>',line)
            #the following statement checks if string between double/single quotes
            if is_between_quotes:
                for notation in is_between_quotes:
                    #orange
                    line = line.replace(notation,'<pre style="color:orange;">'+notation+'</pre>')
            elif is_between_squotes:
                for notation in is_between_squotes:
                    #orange
                    line = line.replace(notation,'<pre style="color:orange;">'+notation+'</pre>')
            if rewrite!='':
                if "#" in original:
                    line = original.replace(original,'<pre style="color:pink;">'+original+'</pre>')
                    rewrite = line
                line_lst.append(rewrite)
                w.write(rewrite)
                w.write('<br>')
                rewrite = ''
            rewrite = line
            for element in RESERVED:
                match = re.search(r'\b'+element+r'\b',line)
                fake_reserved = re.findall(r'\>.*?\<',line)
                if match:
                    rewrite = re.sub(r'\b'+element+r'\b','<pre style="color:aqua">'+element+'</pre>',line)
                    line = rewrite
            if rewrite == '':
                w.write(original)
                w.write('<br>')
            if not line:
                w.write('</body>\n</html>')
                break
            
        
    