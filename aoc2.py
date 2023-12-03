def aoc2(fpath):
	f = open(fpath, mode='r')
	d = f.readlines()
	valid_games = []

	def parse_line(line):
		colors = {"red": 12, "blue": 14, "green": 13}
		spl = line.split(':')
		game = spl[0]
		rounds = spl[1].strip().split(';')
		for rnd in rounds:
			a = rnd.split(',')
			for c in a:
				c = c.strip()
				b = c.split(' ')
				if int(b[0]) > colors[b[1]]:
					return False
		return True

	for i,l in enumerate(d):
		if (parse_line(l)):
			valid_games.append(i+1)
			
	return sum(valid_games)

print(aoc2("aoc2.txt"))
