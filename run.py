from time import sleep,time
from os import system
from sys import argv,exit
import asyncio

def runner(function):
	def func(*args):
		print('c output :\n')
		start = time()
		function(*args)
		end = time()
		print('\n\n<--END-->')
		print('program timetacken : ',int((end-start)*100)/100 , 's')
	return func

@runner
def runc(file):
	system(f'gcc {file[0]} -o ./compile/.{file}cout')
	# system( f"qemu-aarch64  -L /usr/lib/aarch64-linux-gnu ./compile/.{file}cout");
	system( f" ./compile/.{file}cout");

@runner
def runpy(file):
	print(file)
	system(f'python3 {file} ')

def fileChecker(fileT:str,file):
	match(fileT):
		case 'python':filePrefix='.py'
		case 'c':filePrefix='.c'
		case _ : filePrefix='Null'
	if filePrefix not in file:
		print(f'invelid file this is not {fileT} file')
		exit()
		
print(argv)	
if argv[1]=='--codet' and argv[3]=='--file':(fileChecker(argv[2],argv[i]) for i in range(4,len(argv)-5))
else:
	print("Invelid Command")
	print("""
	--codet : code type mean which type of code you want to run 
			[ currently this only have .py --> python .c --> c ]
	
	--file : the programic files which you want to run

	ex : python3 run.py --codet c --file main.py main2.py
	[ you can't interchange codet and file ]
	   """)
	exit()
file = argv[4:]
data = [b'' for i in range(len(file))]

async def Terminal():
	global data
	while True:
		cmd = await asyncio.get_event_loop().run_in_executor(None,input,'terminal # ')
		match(cmd):
			case 'run':
				data = [b'' for i in range(len(file))]
				await asyncio.sleep(3)
			
			case 'exit':exit()
			case 'clear':system('clear')
			case 'help':print('''
		exit : quit the program
		ls : see current directory
		run : run the selected program
		help : asking for help
		''')
	
		if 'ls' in cmd:system(cmd)
		if not cmd:await asyncio.sleep(0.25)
async def checkUpdate():
	global file
	global data
	while True:
		for i in range(len(file)):
			f = open(file[i],'rb')
			tmp_data = f.read()
			f.close()
			if tmp_data != data[i]:
				data[i] = tmp_data
				if argv[2]=='c':
					system('clear')
					runc(file)
					break
				elif argv[2]=='python':
					print('running python')
					system('clear')
					runpy(file[i])
			del tmp_data,f

		await asyncio.sleep(1)

async def main():
	task = [asyncio.ensure_future(i) for i in [checkUpdate(),Terminal()]]
	await asyncio.gather(*task)

if __name__ == '__main__': asyncio.run(main())
