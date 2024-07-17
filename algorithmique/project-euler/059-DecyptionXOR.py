import sys
input = lambda : sys.stdin.readline().strip()

class CryptoXOR :
    global msg, accuracies, alph

    def __init__ (self, keyASCII) :
        self.keyASCII = keyASCII
        self.decryptedMessage = []
        self.decryptedASCII = []
        self.occurences = {i:0 for i in alph}
        self.lenMsg = None

    def decryptMessage (self) :
        """
        Returns string of the decrypted message (for verification) and changes 
        """
        for i in range (len(msg)) :
            self.decryptedASCII.append(msg[i]^self.keyASCII[i%3])
            self.decryptedMessage.append(chr(self.decryptedASCII[i]))
            if (self.decryptedMessage[i].isalpha()) :
                self.occurences[self.decryptedMessage[i].lower()] += 1
        self.lenMsg = sum(i!=' ' for i in self.decryptedMessage)
        for i in self.occurences :
            self.occurences[i] /= self.lenMsg
        

    def getAccuracy(self) :
        """
        Returns <float> : accuracy of the method (sum of absolute values of 
        letters with their english frequencies - only for the 5 most frequent letters)
        """
        self.decryptMessage()
        score = 0
        for i in accuracies :
            score += abs(accuracies[i]-self.occurences[i])
        return score


if __name__ == "__main__" :
    alph = list("abcdefghijklmnopqrstuvwxyz")
    accuracies = {'e':11.16, 'a':8.50, 'r':7.581, 'i':7.545, 'o':7.164, 't':6.951, 'n':6.654} 
    msg = list(map(int, input().split()))
    # lenMsg = sum(i!=' ' for i in msg)
    bestAccuracy = float("+inf")
    bestMessage = []
    for a in alph :
        for b in alph :
            for c in alph :
                currKey = [ord(a), ord(b), ord(c)]
                crypto = CryptoXOR(currKey)
                currAccuracy = crypto.getAccuracy()
                # print(crypto.occurences)
                if currAccuracy < bestAccuracy :
                    bestAccuracy = currAccuracy
                    bestMessage = crypto.decryptedASCII
    print(sum(bestMessage))
