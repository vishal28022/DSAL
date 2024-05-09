class Set:
    def __init__(self, initElementsCount=0):
        self._s = []
        for i in range(initElementsCount):
            e = int(input("Enter Element {}: ".format(i+1)))
            self.add(e)

    def get_set(self):
        return self._s
    
    def __str__(self):
        string = "\n{ "
        for i in range(len(self.get_set())):
            string = string + str(self.get_set()[i])
            if i != len(self.get_set())-1:
                string = string + " , "
        string = string + " }\n"
        return string

    def __len__(self):
        return len(self._s)

    def __contains__(self, e):
        return e in self._s

    def isEmpty(self):
        return len(self._s) == 0

    def add(self, e):
        if e not in self._s:
            self._s.append(e)

    def remove(self, e):
        if e in self._s:
            self._s.remove(e)

    def isSubsetOf(self, setB):
        for e in setB.get_set():
            if e not in self._s:
                return False
        return True

    def isProperSubset(self, setB):
        if self.isSubsetOf(setB) and not setB.isSubsetOf(self):
            return True
        return False

    def union(self, setB):
        newSet = Set()
        for e in self._s:
            newSet.add(e)
        for e in setB.get_set():
            if e not in self._s:
                newSet.add(e)
        return newSet

    def intersect(self, setB):
        newSet = Set()
        for item in self._s:
            if item in setB.get_set():
                newSet.add(item)
        return newSet

    def difference(self, setB):
        newSet = Set()
        for item in self._s:
            if item not in setB.get_set():
                newSet.add(item)
        return newSet

    def __iter__(self):
        return iter(self._s)
