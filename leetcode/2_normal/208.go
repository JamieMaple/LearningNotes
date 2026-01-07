package normal

import "unicode/utf8"

type Trie struct {
	m      map[rune]*Trie
	hasEnd bool
}

func Constructor() Trie {
	return Trie{
		m: map[rune]*Trie{},
	}
}

func (this *Trie) Insert(word string) {
	// apple
	// a -> p -> p
	t := this
	for k, v := range word {
		_, ok := t.m[v]

		if !ok {
			t.m[v] = &Trie{
				map[rune]*Trie{},
				false,
			}
		}
		if k == utf8.RuneCountInString(word)-1 {
			t.m[v].hasEnd = true
		}

		t = t.m[v]
	}
}

func (this *Trie) Search(word string) bool {
	t := this
	for k, v := range word {
		n, ok := t.m[v]

		if !ok {
			return false
		}
		t = n

		// apple -> search app
		if k == len(word)-1 {
			return n.hasEnd
		}
	}

	return true
}

func (this *Trie) StartsWith(prefix string) bool {
	t := this
	for _, v := range prefix {
		n, ok := t.m[v]

		if !ok {
			return false
		}
		t = n
	}

	return true
}
