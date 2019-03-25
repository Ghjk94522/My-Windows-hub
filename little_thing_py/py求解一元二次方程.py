import math
def quadratic(a,b,c):
	if not isinstance(a,(int,float)):
		raise TypeError('bad operand type')
	if not isinstance(b,(int,float)):
		raise TypeError('bad operand type')
	if not isinstance(c,(int,float)):
		raise TypeError('bad operand type')
	if(b * b - 4 * a * c < 0):
		print('No ansewer!')
	elif(b * b - 4 * a * c == 0):
		print(-b / (2 * a))
		return
	else:
		print((math.sqrt(b * b - 4 * a * c) - b) / (2 * a))
		print((-math.sqrt(b * b - 4 * a * c) - b) / (2 * a))
		return

p = float (input('a = '))
q = float (input('b = '))
r = float (input('c = '))
quadratic(p,q,r)
