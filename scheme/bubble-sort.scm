;;;; Bubble sort in Scheme
;;;; Tested with guile.
;;;; This implementation conses like a big dog.
;;;; Two immediate improvements are to support lists of other than
;;;; numeric values and to rewrite the function to be properly tail
;;;; recursive (more recursion, less explicit looping).

(define (bubble-sort lst)
  (do ((i (length lst) (- i 1))
       (sorted-list
        lst
        (cond ((<= (length sorted-list) 1) sorted-list)
              ((< (car sorted-list) (cadr sorted-list))
               (cons (cadr sorted-list)
                     (bubble-sort (cons (car sorted-list)
                                        (cddr sorted-list)))))
              (else (cons (car sorted-list) (bubble-sort (cdr sorted-list)))))))
      ((< i 0) sorted-list)))
