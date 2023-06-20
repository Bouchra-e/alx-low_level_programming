(setq mouse-drag-copy-region t)setq c-default-style "bsd"
     c-basic-offset 8
     tab-width 8
     indent-tabs-mode t)
(require 'whitespace)
(setq whitespace-style '(face empty lines-tail trailing))
(global-whitespace-mode t)
(setq column-number-mode t)
(cua-mode t)
;; Betty Style for C Programming Language
(add-hook 'c-mode-hook
    (lambda () (setq indent-tabs-mode nil)
      (c-set-style "bsd")
      (setq c-basic-offset 8)))
;; Enable flycheck
(global-flycheck-mode)

;; Use clang for checking C code with flycheck
(with-eval-after-load 'flycheck
  (setq-default flycheck-disabled-checkers
                (append flycheck-disabled-checkers
                        '(c/c++-clang)))
  (setq-default flycheck-disabled-checkers
               (append flycheck-disabled-checkers
                        '(c/c++-cppcheck))))
(flycheck-add-mode 'c/c++-clang 'c-mode)
(setq-default scroll-step 1)
(setq-default scroll-conservatively 10000)
(delete-selection-mode 1)
(setq-default transient-mark-mode t)
(setq mouse-drag-copy-region t)
(menu-bar-mode 1)
(tool-bar-mode 1)
(scroll-bar-mode 1)
(menu-bar-mode t)
(tool-bar-mode t)
(mouse-wheel-mode t)
(xterm-mouse-mode t)
(global-set-key [mouse-4] 'scroll-down-line)
(global-set-key [mouse-5] 'scroll-up-line)
(cua-mode t)
