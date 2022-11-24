#!/bin/bash

clean()
{
    echo "Cleaning previous build artifacts"
    if [[ -d "Build" ]]
    then
        rm -rf "Build"
    fi
    if [[ -d "output" ]]
    then
        rm -rf "output"
    fi
}

generate()
{
    echo "Generating CMake files"
    if [[ ! -d "Build" ]]
    then
        mkdir "Build"
    fi

    pushd "Build" || exit 1
    cmake .. || exit 1
    popd
}

build()
{
    echo "Building project"
    if [[ ! -d "Build" ]]
    then
        echo "Build directory not present, generating cmake files"
        generate || exit 1
    else
        pushd "Build" || exit 1
        make || exit 1
        popd
    fi
}

parseArgs()
{
    CLEAN="false"
    BUILD="false"
    GENERATE="false"

    local idx=1
    while [ "$idx" -le "$#" ]; do
        local parm="${!idx}"
        idx=$((idx + 1))

        case "${parm,,}" in
            -h | --help)
                printHelp
                exit 1
                ;;
            -c | --clean)
                CLEAN="true"
                ;;
            -b | --build)
                BUILD="true"
                ;;
            -g | --generate)
                GENERATE="true"
                ;;
            *)
                printHelp
                exit 1
                ;;
        esac
    done
}

main()
{
    parseArgs "$@" || return 1

    if [[ $CLEAN == "true" ]]
    then
        clean
    fi

    if [[ $GENERATE == "true" ]]
    then
        generate
    fi

    if [[ $BUILD == "true" ]]
    then 
        build
    fi
}

main "$@"
