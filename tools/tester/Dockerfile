FROM charming/python:latest

RUN mkdir /charming

WORKDIR /charming

COPY test_sample.py /charming/test_sample.py

ENV PATH=/opt/python-2.7/bin:$PATH \
    LD_LIBRARY_PATH=/charming/lib:$LD_LIBRARY_PATH \
    PYTHONPATH=/charming/lib:$PYTHONPATH

CMD ["python", "test_sample.py"]
