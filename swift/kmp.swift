// KMP search in Swift
// https://en.wikipedia.org/wiki/Knuth–Morris–Pratt_algorithm

func kmp_table(sought: String) -> Array<Int> {
  var T = Array<Int>(repeating: -1, count: sought.count) // (the table, computed elsewhere)
  var pos: Int = 1 // (the current position we are computing in T)
  var cnd: Int = 0 // (the zero-based index in sought of the next character of the current candidate substring)

  T.insert(-1, at: 0)

  while pos < sought.count {
    let pIndex = sought.index(sought.startIndex, offsetBy: pos)
    let cIndex = sought.index(sought.startIndex, offsetBy: cnd)

    if sought[pIndex] == sought[cIndex] {
      T.insert(T[cnd], at: pos)
      pos = pos + 1
      cnd = cnd + 1
    } else {
      T.insert(cnd, at: pos)
      cnd = T[cnd] // (to increase performance)

      while cnd >= 0 && sought[pIndex] != sought[cIndex] {
        cnd = T[cnd]
      }

      pos = pos + 1
      cnd = cnd + 1
    }
  }

  T[pos] = cnd
  return T
}

func kmp_search(sought: String, string: String) -> Array<Int> {
  var m: Int = 0 // (the beginning of the current match in string)
  var i: Int = 0 // (the position of the current character in sought)
  var T = kmp_table(sought: sought) // (the table, computed elsewhere)

  var nP = 0 // (number of positions)
  var P = Array<Int>()

  while (m + i) < string.count {
    let wIndex = sought.index(sought.startIndex, offsetBy: i)
    let sIndex = string.index(string.startIndex, offsetBy: i + m)

    if sought[wIndex] == string[sIndex] {
      i = i + 1
      if i == sought.count {
        // (occurrence found, if only first occurrence is needed, m may be returned at this point)
        P.insert(m, at: nP)
        nP = nP + 1
        m = m + i - T[i]
        i = T[i] // (T[length(sought)] can't be -1)

      }
    } else {
      if T[i] > -1 {
        m = m + i - T[i]
        i = T[i]
      } else {
        m = m + i + 1
        i = 0
      }
    }
  }

  return P
}

func main() {
  let string = "aabcaabxaaaz"

  assert(kmp_search(sought:"bxa", string:string) == [6])
  assert(kmp_search(sought:"aaaa", string:string) == [])
  assert(kmp_search(sought:"aaa", string:string) == [8])
  assert(kmp_search(sought:"z", string:string) == [11])
  assert(kmp_search(sought:"a", string:string) == [0, 1, 4, 5, 8, 9, 10])
  assert(kmp_search(sought:"g", string:string) == [])
}

main();
