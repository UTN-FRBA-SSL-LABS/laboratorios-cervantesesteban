#include <stdio.h>
#include "../src/carrito.h"
#include "minunit/minunit.h"

/*
 * Tests de integracion: verifican que las funciones trabajan bien
 * en combinacion, no de forma aislada.
 */

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE D — Escribir el test guiado (ver README.md, Parte 8)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_compra_con_descuento() siguiendo la guia del .md */

void test_compra_con_descuento(void) {
    printf("\n[compra con descuento]\n");
    Carrito c;
    carrito_init(&c);

    Producto pan = {"Pan", 200, 3};
    Producto leche = {"Leche", 350, 2};

    ASSERT_IGUAL(1, carrito_agregar(&c, pan));
    ASSERT_IGUAL(1, carrito_agregar(&c, leche));

    /* Verificar el total sin descuento (600 + 700 = 1300) */
    int total = carrito_total(&c);
    ASSERT_IGUAL(1300, total);

    /* Verificar con 10% de descuento usando carrito_descuento */
    int total_con_descuento = carrito_descuento(total, 10);
    ASSERT_IGUAL(1170, total_con_descuento);
}

/* ═══════════════════════════════════════════════════════════════════════════
 *  PARTE E — Disenar un test propio (ver README.md, Parte 9)
 * ═══════════════════════════════════════════════════════════════════════════ */

/* TODO: escribir test_agregar_hasta_llenar() */

void test_agregar_hasta_llenar(void) {
    printf("\n[agregar hasta llenar]\n");
    Carrito c;
    carrito_init(&c);

    Producto p = {"Galletitas", 150, 1};

    /* 1. Llenar el carrito hasta su capacidad máxima (4 productos) */
    for (int i = 0; i < MAX_ITEMS; i++) {
        ASSERT_IGUAL(1, carrito_agregar(&c, p));
    }

    /* 2. Verificar que el conteo es MAX_ITEMS */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));

    /* 3. Verificar que intentar agregar uno más devuelve 0 */
    ASSERT_IGUAL(0, carrito_agregar(&c, p));

    /* 4. Verificar que el conteo sigue siendo MAX_ITEMS (no cambió) */
    ASSERT_IGUAL(MAX_ITEMS, carrito_contar(&c));
}

int main(void) {
    printf("=== Tests de integracion ===");
    /* Descomentar a medida que agregues las funciones: */
    test_compra_con_descuento(); 
    test_agregar_hasta_llenar();
    RESUMEN();
    return EXIT_CODE();
}
