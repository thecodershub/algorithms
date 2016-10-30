func quicksort<T: Comparable>(var list: T[]) -> T[] {
    if list.count <= 1 {
        return list
    }

    let pivot = list.removeAtIndex(0)
    return quicksort(list.filter { $0 <= pivot }) + [pivot] + quicksort(list.filter { $0 >  pivot })
}

let list: Int[] = [1, -5, 9, 8, 110, 42, -70, 0, 3, 4, 5, 2, 2, 1, 0, 1]
let sortedList = quicksort(list)

let strings = ["a", "c", "d", "a", "e", "b", "a", "f", "e"]
let sortedStrings = quicksort(strings)

struct Vector: Comparable {
    var x: Double = 0.0, y: Double = 0.0
}

func <(p: Vector, q: Vector) -> Bool {
    return p.x < q.x && p.y < q.y
}

func ==(p: Vector, q: Vector) -> Bool {
    return p.x == q.x && p.y == q.y
}

let vectors = [Vector(x: 1.0, y: 2.0), Vector(x: 0.0, y: 1.0)]
let sortedVectors = quicksort(vectors)
