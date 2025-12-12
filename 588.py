from enum import Enum

class TYPE(Enum):
    TYPE = 0
    DICT = 1
    FILE = 2

class FileSystem:

    def __init__(self):
        self.system = dict()
        self.system[TYPE.TYPE] = TYPE.DICT

    def getPath(self, path: str) -> (str, dict):
        pos = self.system
        paths = path.split('/')
        for p in paths:
            if p != '':
                pos = pos[p]
        return (paths[-1], pos)
    
    def ls(self, path: str) -> List[str]:
        name, pos = self.getPath(path)
        if pos[TYPE.TYPE] == TYPE.FILE:
            return [name]
        ans = []
        for file in pos.keys():
            if file != TYPE.TYPE:
                ans.append(file)
        ans.sort()
        return ans

    def mkdir(self, path: str) -> None:
        paths = path.split('/')
        pos = self.system
        for p in paths:
            if p != '':
                if p not in pos:
                    pos[p] = {TYPE.TYPE: TYPE.DICT}
                pos = pos[p]

    def addContentToFile(self, filePath: str, content: str) -> None:
        paths = filePath.split('/')
        pos = self.system
        for p in paths:
            if p != '':
                if p not in pos:
                    pos[p] = dict()
                pos = pos[p]
        if TYPE.TYPE not in pos.keys():
            pos[TYPE.TYPE] = TYPE.FILE
            pos["str"] = ""
        pos["str"] += content

    def readContentFromFile(self, filePath: str) -> str:
        name, pos = self.getPath(filePath)
        return pos["str"]
        


# Your FileSystem object will be instantiated and called as such:
# obj = FileSystem()
# param_1 = obj.ls(path)
# obj.mkdir(path)
# obj.addContentToFile(filePath,content)
# param_4 = obj.readContentFromFile(filePath)