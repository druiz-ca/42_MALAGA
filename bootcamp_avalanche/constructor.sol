// SPDX-License-Identifier: MIT
pragma solidity ^0.8.26;

contract MyContract
{
    uint256 public myNumber;
    address public owner;
    // public-> son accesibles también desde fuera del contrato.
    // Solidity crea autom. los getters para estas var. para poder extraer los datos desde el exterior!

    // Función que se ejecuta al desplegar el contrato
    constructor(uint256 _myNumber)
    {
        myNumber = _myNumber;
        owner = msg.sender; 
        // Indica quien esta interactuando con el contrato
        // msg.sender = dirección de la cuenta que desplegó el contrato
            // útil para seguridad: verificar permisos, autenticar usuarios, etc.
    }
}