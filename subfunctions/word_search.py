# Long version : 
# logic steps : 
# 1) convert to string, make phrase lower case, split phrase into words
# 2) remove undesired characters : search over letters and remove specific characters 
# 3) search keyword in phrase - get position of keyword in phrase
# 4) search across phrases, if keyword present position are given put index
def word_search_long(doc_list, keyword):
    """
    Takes a list of documents (each document is a string) and a keyword. 
    Returns list of the index values into the original list for all documents 
    containing the keyword.

    Example:
    doc_list = ["The Learn Python Challenge Casino.", "They bought a car", "Casinoville"]
    >>> word_search(doc_list, 'casino')
    >>> [0]
    """

    # doc_list = ["The Learn Python Challenge Casino.", "They bought a car,", "Casinoville"]
    # keyword = 'casino'
    # keyword = 'car'

    keyword = keyword.lower()
    indout = []
    for i in doc_list:
        # print('i : ' + str(i))
        phrase = str(i).lower()
        phrase2 = phrase.split()
        print('phrase2 : ' + str(phrase2))
        
        # need to get rid of .
        undesired_char_list = ['.', ',', '?', ':', '!', ';']
        uphrase = []
        uphrase_word = []
        for uchar in undesired_char_list:
            wordlen = []
            phrase3 = []
            for k in range(len(phrase2)):
                letter = [phrase2[k][q] for q in range(len(phrase2[k])) if phrase2[k][q] != uchar]
                # print('letter : ' + str(letter))
                word = ''
                for x in letter:
                    word += x 
                print('word : ' + str(word))
                wordlen = wordlen + [len(word)]
                phrase3 = phrase3 + [word]
            uphrase = uphrase + [phrase3]
            uphrase_word = uphrase_word + [wordlen]
        
        out = []
        for q in range(len(uphrase_word)):
            out = out + [sum(uphrase_word[q])]
        # print('out : ' + str(out))
        
        prev_len = out[0]
        keepind = 0
        for q in range(1, len(out)):
            if prev_len > out[q]:
                keepind = q
                prev_len = out[q]
        
        phrase3 = uphrase[keepind]
        # print('phrase3 : ' + str(phrase3))
            
        u = [val == keyword for val in phrase3]
        # print('u : ' + str(u))
        index = [j for j in range(len(u)) if u[j] == True]
                
        indout = indout + [index]
    print('indout : ' + str(indout))

    indices = [i for i in range(len(indout)) if indout[i]]
    print('indices : ' + str(indices))

    return indices
    
    
# Short version : 
# logic steps : 
# 1) split phrase into words
# 2) make each word lower case and remove characters at the end of word
# 3) search lower case keyword in phrase - save phrase index directly 
def word_search_short(documents, keyword):
    # list to hold the indices of matching documents
    indices = [] 
    # Iterate through the indices (i) and elements (doc) of documents
    for i, doc in enumerate(documents):
        # Split the string doc into a list of words (according to whitespace)
        tokens = doc.split()
        # Make a transformed list where we 'normalize' each word to facilitate matching.
        # Periods and commas are removed from the end of each word, and it's set to all lowercase.
        normalized = [token.rstrip('.,').lower() for token in tokens]
        # Is there a match? If so, update the list of matching indices.
        if keyword.lower() in normalized:
            indices.append(i)
    return indices
    
    
    
def multi_word_search(doc_list, keywords):
    """
    Takes list of documents (each document is a string) and a list of keywords.  
    Returns a dictionary where each key is a keyword, and the value is a list of indices
    (from doc_list) of the documents containing that keyword

    >>> doc_list = ["The Learn Python Challenge Casino.", "They bought a car and a casino", "Casinoville"]
    >>> keywords = ['casino', 'they']
    >>> multi_word_search(doc_list, keywords)
    {'casino': [0, 1], 'they': [1]}
    """
    return {keyw: word_search_short(doc_list, keyw) for keyw in keywords}