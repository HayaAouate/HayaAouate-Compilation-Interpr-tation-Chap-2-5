.section .text
.global median3

median3:
    cmp %rsi, %rdi      # Comparer a et b
    jle a_inf_b         # Si a <= b, sauter vers a_inf_b

    # --- Cas où a > b ---
    cmp %rdi, %rdx      # Comparer c et a
    jg  ret_a           # Si c > a, alors b < a < c -> Médiane est a
    cmp %rsi, %rdx      # Comparer c et b
    jg  ret_c           # Si c > b (et c <= a), alors b < c <= a -> Médiane est c
    jmp ret_b           # Sinon, c <= b < a -> Médiane est b

a_inf_b:
    # --- Cas où a <= b ---
    cmp %rsi, %rdx      # Comparer c et b
    jl  c_inf_b         # Si c < b, on doit encore comparer c et a
    jmp ret_b           # Si c >= b, alors a <= b <= c -> Médiane est b

c_inf_b:
    cmp %rdi, %rdx      # Comparer c et a
    jg  ret_c           # Si c > a, alors a < c < b -> Médiane est c
    jmp ret_a           # Sinon, c <= a < b -> Médiane est a

# Etiquettes de retour
ret_a: mov %rdi, %rax; ret
ret_b: mov %rsi, %rax; ret
ret_c: mov %rdx, %rax; ret


