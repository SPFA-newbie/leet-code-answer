class Solution:
    def capitalizeTitle(self, title: str) -> str:
        title=title.lower()
        words=title.split()
        res=""
        for word in words:
            if len(word)>2:
                word=word.title()
            res=res+word+" "
        return res[:-1]
