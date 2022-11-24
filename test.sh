#!/bin/bash

run_unit()
{
    TEST_EXE="${EXEC_BASE}Unit"
    pushd "${BIN_DIR}" || exit 1
    mkdir data
    cp  ../../tests/data/*.txt ./data || exit 1
    chmod +x "$TEST_EXE"
    ./"$TEST_EXE"
    RESULT=$(($RESULT + $?))
    rm -rf data
    popd
}

run_integration()
{
    TEST_EXE="${EXEC_BASE}Integration"
    pushd "${BIN_DIR}" || exit 1
    mkdir data
    cp  ../../tests/data/*.txt ./data || exit 1
    chmod +x "$TEST_EXE"
    ./"$TEST_EXE"
    RESULT=$(($RESULT + $?))
    rm -rf data
    popd
}

parseArgs()
{
    RUN_UNIT="false"

    local idx=1
    while [ "$idx" -le "$#" ]; do
        local parm="${!idx}"
        idx=$((idx + 1))

        case "${parm,,}" in
            -h | --help)
                printHelp
                exit 1
                ;;
            -u | --unit)
                RUN_UNIT="true"
                ;;
            -i | --integration)
                RUN_INTEGRATION="true"
                ;;
            *)
                printHelp Unexpected parameter ${parm}
                exit 1
                ;;
        esac
    done
}

main()
{
    BIN_DIR="output/bin"
    EXEC_BASE="LibAOCPP"
    RESULT=0

    parseArgs "$@" || exit 1

    if [[ $RUN_UNIT == "true" ]]
    then
        run_unit
    fi

    if [[ $RUN_INTEGRATION == "true" ]]
    then
        run_integration
    fi
    return $RESULT
}

main "$@"
