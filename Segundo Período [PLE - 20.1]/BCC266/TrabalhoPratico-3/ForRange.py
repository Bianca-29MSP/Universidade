class ForRange:
    
    def __init__(self, forRangeStartC1, forRangeStartC2, forRangeStartC3,
    forRangeEndC1, forRangeEndC2, forRangeEndC3, RAM):
        self.forRangeStartC1 = forRangeStartC1
        self.forRangeStartC2 = forRangeStartC2
        self.forRangeStartC3 = forRangeStartC3
        self.forRangeEndC1 = forRangeEndC1
        self.forRangeEndC2 = forRangeEndC2
        self.forRangeEndC3 = forRangeEndC3
        self.RAM = RAM

    def getRangeStart(self, c):
        if c == 'C1':
            return self.forRangeStartC1
        elif c == 'C2':
            return self.forRangeStartC2
        elif c == 'C3':
            return self.forRangeStartC3
        elif c == 'R':
            return 0

    def getRangeEnd(self, c):
        if c == 'C1':
            return self.forRangeEndC1
        elif c == 'C2':
            return self.forRangeEndC2
        elif c == 'C3':
            return self.forRangeEndC3
        elif c == 'R':
            return self.RAM