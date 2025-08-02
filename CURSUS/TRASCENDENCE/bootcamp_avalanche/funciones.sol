
pragma solidity ^0.8.26;

/* contract Ejemplodecontrato
{
    uint private counter;
    // private: solo podemos comprobarlo mediante funciones

    function incrementCounter() public {
        counter++;
    }

    function getCounter() public view returns (uint)
    {
        return counter;
    }

    function deposit() public payable {}
} */

// SPDX-License-Identifier: MIT
pragma solidity ^0.8.0;

contract AlmacenamientoSimple {
    // Variable de estado para almacenar un número
    uint256 private numeroAlmacenado;

    // Función para almacenar un número
    function almacenarNumero(uint256 _numero) public {
        numeroAlmacenado = _numero;
    }

    // Función para recuperar el número almacenado
    function recuperarNumero() public view returns (uint256) {
        return numeroAlmacenado;
    }
}