from mal_types import MalType, MalSym, MalList

# Environment
class Env():
    def __init__(self, outer=None, binds=None, exprs=None):
        self.data = {}
        self.outer = outer or None

        if binds:
            assert isinstance(binds, MalList) and isinstance(exprs, MalList)
            for i in range(len(binds)):
                bind = binds[i]
                assert isinstance(bind, MalSym)
                if bind.value == u"&":
                    bind = binds[i+1]
                    assert isinstance(bind, MalSym)
                    self.data[bind.value] = exprs.slice(i)
                    break
                else:
                    self.data[bind.value] = exprs[i]

    def find(self, key):
        assert isinstance(key, MalSym)
        if key.value in self.data: return self
        elif self.outer:           return self.outer.find(key)
        else:                      return None

    def set(self, key, value):
        assert isinstance(key, MalSym)
        assert isinstance(value, MalType)
        self.data[key.value] = value
        return value

    def get(self, key):
        assert isinstance(key, MalSym)
        env = self.find(key)
        if not env: raise Exception(u"'" + key.value + u"' not found")
        return env.data[key.value]